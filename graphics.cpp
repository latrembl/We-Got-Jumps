#include "graphics.h"
#include "shapes.h"
#include "stage.h"
#include "playerClass.h"
#include "save.h"
#include "load.h"
#include "menu.h"
#include "platform.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

GLdouble width, height;
//game mode booleans
bool start = true;
bool gameRunning = false;
bool gamePaused = false;
bool gameOver = false;
int difficulty = 1;
int level = 1;
int wd;
playerClass player;  //change to player
vector<Platform> platforms; //Array list of all the platforms on-screen
Save gameSave = Save();
load gameLoad = load();
int stageFallMod = 0; //Value used to handle when the platforms will fall
double gravity = 2.75; //Default falling value
double friction = 0.75;
Platform playerOn; //The platform that the player has landed on
bool* keyStates = new bool[256]; // Create an array of boolean values of length 256 (0-255)
bool* keySpecialStates = new bool[256]; // Create an array of boolean values of length 256 (0-255)

bool onPlat1 = false;



void init() {

    //Initialize the random for platforms
    srand(time(NULL));
    //Screen dimensions
    width = 1200;
    height = 800;

    player.setScore(0);

    //Rectangle initialization for the player
    player.playerIcon.setDimensions(25, 25);
    player.playerIcon.setColor(0.1, 0.1, 0.9);
    player.playerIcon.setPoint(425, 10);
    //Player starting position
    player.setX(425);
    player.setY(10);
    //TEST//cout << "Player object drawn" << endl;
    //TESTcout << "Your score is: " << player.getScore() << endl;

    //The two initial platforms that load in as the game starts up.
    Platform platform0 = Platform(2000, 2000,1,1,1);           //rendered off screen to avoid bug when increasing levels
    Platform platform1 = Platform(400, 300);
    Platform platform2 = Platform(600, 650);
    platforms.push_back(platform0);
    platforms.push_back(platform1);
    platforms.push_back(platform2);
    //Initially set the players y velocity to the gravity, so that it falls down when the game starts
    player.setYVelocity(gravity);
    //Go through and initialize the special key pressed to false.
    for (int i = 0; i < 256; i ++) {
        keySpecialStates[i] = false;
    }
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

/**
 * Return the player to its original position
 */
void resetPlayer() {
    player.setX(425);
    player.setY(10);
    player.playerIcon.setPoint(player.getX(), player.getY());
    player.setOnStage(false);
}

/**
 * Check to see if two rectangles are overlapping.

 */
bool isOverlappingRects(const Rect &r1, const Rect &r2) {
    // if one rectangle is to the left of the other
    // or above the other, then they are not overlapping.
    return !((r1.getCenter().x + (r1.getWidth() / 2.0) < r2.getCenter().x - (r2.getWidth() / 2.0)) ||
             // r1 is left of r2
             (r2.getCenter().x + (r2.getWidth() / 2.0) < r1.getCenter().x - (r1.getWidth() / 2.0)) ||
             // r2 is left of r1
             (r1.getCenter().y - (r1.getLength() / 2.0) > r2.getCenter().y + (r2.getLength() / 2.0)) ||
             // r1 is below r2
             (r2.getCenter().y - (r2.getLength() / 2.0) > r1.getCenter().y + (r1.getLength() / 2.0))); // r2 is below r1
}

/**
 * Function to shift all of the platforms on screen down
 */
void shiftStageDown(int difficulty) {
    for (int i = 0; i < platforms.size()-1; i++) {          //-1 fixes weird rendering issues
        platforms.at(i).move(0, 2+ difficulty);             //adjust platform movement based on difficulty
        //If the platforms exit the bottom of the screen, then erase it from our arrayList
        if (platforms.at(i+1).getY() > 810) {
            platforms.erase(platforms.begin() + i);        //+1 fixes weird rendering issues
        }
    }   //glutPostRedisplay();
    //If the player is on a stage, when it falls, move the player as well.
    if (player.isOnStage()) {
        player.move(player.getXVelocity(), 2+ difficulty);  //adjust player movement based on difficulty
    }
    //Redraw the player on the screen to reflect the change
    player.draw();
    glutPostRedisplay();
}

/**
 * Function to add another new layer of platforms to the screen.
 */
void addNewPlatform() {
    Platform plat1 = Platform(rand() % 150 + 150,rand() % -50 - 80);
    Platform plat2 = Platform(rand() % 250 + 450,rand() % -50 - 150);
    Platform plat3 = Platform(rand() % 350 + 750,rand() % -50 - 100);
    platforms.push_back(plat1);
    platforms.push_back(plat2);
    platforms.push_back(plat3);
}

//function to draw score message
void drawScore() {
    Menu().drawText("Score: " + to_string(player.getScore()),2,1,1,0.5,20,40);
}

//function to level message
void drawLevel() {
    Menu().drawText("Level: " + to_string(level),2,1,1,0.5,20,60);
}

//when starting new game function
void newGame() {
    level = 1;
    difficulty = 1;
    start = false;
    gamePaused = false;
    gameOver = false;
    gameRunning = true;
    platforms.clear();
    stageFallMod = 0; //Value used to handle when the platforms will fall
    resetPlayer();
    player.setScore(0);
    //adjusting height of starting platform based on loaded score and difficulty
    int startPlatformHeight1 = 300;
    int startPlatformHeight2 = 650;
    for ( int i = 0; i<1000; i+=5)
    if (difficulty > i) {startPlatformHeight1 -= 150; startPlatformHeight2 -= 150;
    }
    //Initialize the random for platforms
    srand (time(NULL));
    //Screen dimensions
    width = 1200;
    height = 800;

    //The two initial platforms that load in as the game starts up.
    Platform platform0 = Platform(2000, 2000,1,1,1);           //rendered off screen to avoid bug when increasing levels
    Platform platform1 = Platform(400, startPlatformHeight1);                   //start platform, the one that player lands on
    Platform platform2 = Platform(600, startPlatformHeight2);
    platforms.push_back(platform0);
    platforms.push_back(platform1);
    platforms.push_back(platform2);
    //Initially set the players y velocity to the gravity, so that it falls down when the game starts
    player.setYVelocity(gravity);
    //Go through and initialize the special key pressed to false.
    for (int i = 0; i < 256; i ++) {
        keySpecialStates[i] = false;
    }
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    //Function calls to handle the keyboard input from the normal keys and the special keys
    //Handling keyboard inputs this way allows for multiple inputs at once
    keyOperations();
    keySpecialOperations();

    //player.move(0, player.getDeltaMovement(), 4);
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //BEGIN GAME LOOPS--------------------------------------------------------------------------------------------------

    //START MENU LOOP---------------------------------------------------------------------------------------------------
    if (start) {
        Menu().drawStartMenu();
        glFlush();
    }

    //PAUSE MENU LOOP---------------------------------------------------------------------------------------------------
    if (gamePaused && !gameOver) {
        player.draw();
        for (int i = 1; i < platforms.size(); i++) {
            platforms.at(i).draw();
        }
        //draw score and level messages
        drawScore();
        drawLevel();
        //draw menu messages
        Menu().drawScreenMenu();
        Menu().drawPauseMenu();
        glFlush();
    }

    //GAME RUNNING LOOP-------------------------------------------------------------------------------------------------
    if (gameRunning) {
        gameRunning = true;
        gameOver = false;


        //LEVEL CONDITIONS----------------------------------------------------------------------------------------------

        //level 1
        if (player.getScore() >= 0 && player.getScore()<100) {   //need && for load game scenario (wont add extra plats)
            if (stageFallMod % 500 == 0) {addNewPlatform();}
            difficulty = 1;
            level = 1;
        }

        //level 2
        if (player.getScore() == 100){difficulty = 5;level = 2; if(stageFallMod % 50 == 0){addNewPlatform();}};
        if (player.getScore() > 100 && player.getScore() < 200) {
            if (stageFallMod % 400 == 0) {addNewPlatform();}
            difficulty = 5;
            level = 2;
        }

        //level 3
        if (player.getScore() == 200){difficulty = 10;level = 3; if(stageFallMod % 50 == 0){addNewPlatform();}};
        if (player.getScore() > 200 && player.getScore() < 300) {
            if (stageFallMod % 200 == 0) {addNewPlatform();}
            difficulty = 10;
            level = 3;
        }

        //level 4
        if (player.getScore() == 300){difficulty = 15;level = 4; if(stageFallMod % 50 == 0){addNewPlatform();}};
        if (player.getScore() > 300 && player.getScore() < 400) {
            if (stageFallMod % 150 == 0) {addNewPlatform();}
            difficulty = 15;
            level = 4;
        }

        //level 5
        if (player.getScore() == 400){difficulty = 20;level = 5; if(stageFallMod % 50 == 0){addNewPlatform();}};
        if (player.getScore() > 400 && player.getScore() < 500) {
            if (stageFallMod % 100 == 0) {addNewPlatform();}
            difficulty = 20;
            level = 5;
        }

        //level 6
        if (player.getScore() == 500){difficulty = 25;level = 6; if(stageFallMod % 50 == 0){addNewPlatform();}};
        if (player.getScore() > 500 && player.getScore() < 600) {
            if (stageFallMod % 90 == 0) {addNewPlatform();}
            difficulty = 25;
            level = 6;
        }

        //level 7
        if (player.getScore() == 600){difficulty = 30;level = 7; if(stageFallMod % 50 == 0){addNewPlatform();}};
        if (player.getScore() > 600 && player.getScore() < 700) {
            if (stageFallMod % 90 == 0) {addNewPlatform();}
            difficulty = 30;
            level = 7;
        }

        //level 8
        if (player.getScore() == 700){difficulty = 35;level = 8; if(stageFallMod % 50 == 0){addNewPlatform();}};
        if (player.getScore() > 700 && player.getScore() < 800) {
            if (stageFallMod % 90 == 0) {addNewPlatform();}
            difficulty = 35;
            level = 8;
        }

        //level 9
        if (player.getScore() == 800){difficulty = 45;level = 9; if(stageFallMod % 50 == 0){addNewPlatform();}};
        if (player.getScore() > 800) {
            if (stageFallMod % 40 == 0) {addNewPlatform();}
            difficulty = 45;
            level = 9;
        }




        //UPDATE PLAYER POSITION AND MOVE PLATFORMS DOWN----------------------------------------------------------------
        if (stageFallMod % 7 == 0) {
            shiftStageDown(difficulty);
        }

        for (int i = 0; i < platforms.size(); i++) {
            platforms.at(i).draw();
        }

        player.setYVelocity((player.getYVelocity() * friction) + gravity);

        //TEST//cout << "Player y: " << player.playerIcon.getY()<< endl;

        //Check to see if any of the platforms are overlapping with the player's rectangle.
        for (int i = 0; i < platforms.size(); i++) {
            if (isOverlappingRects(player.getPlayerIcon(), platforms.at(i).getPlatformDisplay())) {
                //TEST//cout << "overlapping" << endl;
                double topPlatform = (platforms.at(i).getPlatformDisplay().getCenter().y -
                                      (0.5 * platforms.at(i).getPlatformDisplay().getLength()));
                //TEST//cout << topPlatform << endl;
                double bottomPlatform = (platforms.at(i).getPlatformDisplay().getCenter().y +
                                         (0.5 * platforms.at(i).getPlatformDisplay().getLength()));
                double topIcon = (player.getPlayerIcon().getCenter().y - (0.5 * player.getPlayerIcon().getLength()));
                double bottomIcon = (player.getPlayerIcon().getCenter().y + (0.5 * player.getPlayerIcon().getLength()));
                //TEST//cout << bottomIcon << endl;
                if (bottomIcon > topPlatform) {
                    if (!platforms.at(i).isHasBeenLandedOn()) {
                        platforms.at(i).platformDisplay.setColor(0.5, 0.5, 0.5);
                        platforms.at(i).setHasBeenLandedOn(true);
                        glutPostRedisplay();
                        player.addScore();
                    }
                    player.setYVelocity(0);
                    player.setOnStage(true);
                    playerOn = platforms.at(i);
                    while (isOverlappingRects(player.getPlayerIcon(), platforms.at(i).getPlatformDisplay())) {
                        player.move(0, -1);
                        player.draw();
                    }
                }
            }
        }
        player.setXVelocity(player.getXVelocity() * friction);

        double leftIcon = player.getPlayerIcon().getCenter().x - (0.5 * player.getPlayerIcon().getWidth());
        double rightIcon = player.getPlayerIcon().getCenter().x + (0.5 * player.getPlayerIcon().getWidth());
        double leftPlatform = playerOn.getPlatformDisplay().getCenter().x -
                              (0.5 * playerOn.getPlatformDisplay().getWidth());
        double rightPlatform = playerOn.getPlatformDisplay().getCenter().x +
                               (0.5 * playerOn.getPlatformDisplay().getWidth());

        if (leftIcon < rightPlatform && rightIcon > leftPlatform && player.isOnStage()) {
            player.move(player.getXVelocity(), 0);
        } else {
            player.move(player.getXVelocity(), player.getYVelocity());
            player.setOnStage(false);
        }

        player.draw();

        //REDRAW MESSAGES SO THEY OVERLAP THE PLATFORMS BUT DON'T OVERLAP GAME OVER MENU
        //draw score and level messages
        drawScore();
        drawLevel();
        //Side menu
        Menu().drawScreenMenu();

        //GAME OVER-----------------------------------------------------------------------------------------------------
        if (player.playerIcon.getY()>=810) { //player falls out the bottom of the window
            gameOver = true;
            gameRunning = false;
            //END MENU LOOP---------------------------------------------------------------------------------------------
            if (gameOver) {
                gameRunning = false;
                player.draw();
                for (int i = 0; i < platforms.size(); i++) {
                    platforms.at(i).draw();
                }
                //draw score and level messages
                drawScore();
                drawLevel();
                Menu().drawEndScreen();
                glFlush();
            }
        }

        glFlush();  // Render now
        stageFallMod++;
    } //END GAME RUNNING LOOP-------------------------------------------------------------------------------------------
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    keyStates[key] = true; // Set the state of the current key to pressed

    //JUMP - SPACEBAR KEY-----------------------------------------------------------------------------------------------
            if (key == 32) {
                if (player.isOnStage()) {
                    player.setOnStage(false);
                    player.jump();
                    player.move(player.getXVelocity(), player.getYVelocity());
                }
            }

    //PAUSE GAME - 'p' KEY----------------------------------------------------------------------------------------------
    if (!start && !gameOver && key == 112) {     //not on start menu and key 'p'
        if (!gamePaused) {
            gamePaused = true;      //if not paused then pause
            gameRunning = false;    //stop game
        } else if (gamePaused) {
            gamePaused = false;     //if paused then unpause
            gameRunning = true;     //start game
        }
    }

    //SAVE GAME - 's' KEY-----------------------------------------------------------------------------------------------
    if (!start && !gameOver && key == 115) {
        //TEST//cout << "You have saved the game." << endl;
        gameSave.saveScore(player.getScore());
        //TEST//cout << "Your score has been saved to jumpScores.txt" << endl;
        for (int time=0; time < 1000;time++) {
            Menu().drawText("GAME SAVED",2,1,1,0.5,550,50);
            glFinish();
        }
    }

    //LOAD GAME - 'l' KEY-----------------------------------------------------------------------------------------------
    if (key == 108) {
        //TEST//cout << "You have loaded the most recent game. " << endl;
        newGame();
        int newScore = gameLoad.loadScore();
        player.setScore(newScore);
        //TEST//cout << "Your score is now " << newScore << ". " << endl;
        for (int time=0; time < 1000;time++) {
            Menu().drawText("LOADING GAME...", 2, 1, 1, 0.5, 550, 100);
            glFinish();
        }
    }
}

//Function to handle the special keys when pressed
//Gets the key that was pressed and sets the corresponding number in the list to true
void kbdS(int key, int x, int y) {
    keySpecialStates[key] = true; // Set the state of the current key to pressed
}

//Function that resets the keys value to false when the key is released
void keySpecialUp (int key, int x, int y) {
    keySpecialStates[key] = false; // Set the state of the current key to pressed
}

void keySpecialOperations() {
    if (keySpecialStates[GLUT_KEY_LEFT]) { // If the left arrow key has been pressed
        //TEST//cout << "left pressed" << endl;
        player.setXVelocity(player.getXVelocity() - 5);
        player.setYVelocity(player.getYVelocity() + gravity);
    }
    if (keySpecialStates[GLUT_KEY_RIGHT]) { // If the right arrow key has been pressed
        //TEST//cout << "right pressed" << endl;
        player.setXVelocity(player.getXVelocity() + 5);
        player.setYVelocity(player.getYVelocity() + gravity);

    }
    if (keySpecialStates[GLUT_KEY_DOWN]) { // If the down arrow key has been pressed
        //TEST//cout << "down pressed" << endl;
        if (!player.isOnStage()) {
            player.setYVelocity(player.getYVelocity() + 3);
        }
    }
}

void keyUp (unsigned char key, int x, int y) {
    keyStates[key] = false; // Set the state of the current key to not pressed
}

void keyOperations () {
    // escape
    if (keyStates[27]) {
        glutDestroyWindow(wd);
        exit(0);
    }
}

void cursor(int x, int y) {
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    //START GAME - LEFT CLICK-------------------------------------------------------------------------------------------
    if (start && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        start = false;               //stop start menu
        gameRunning = true;          //start game
    }

    //RESTART GAME - RIGHT CLICK----------------------------------------------------------------------------------------
    //if ((gameOver && key == 114) || (gamePaused && key == 114)) {     //only restart when paused or game over
    if ((!start && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)) {       //restart any time when not at start menu
        gamePaused = false;
        gameOver = false;
        gameRunning = true;
        newGame();
    }
}

void timer(int extra) {
    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char **argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int) width, (int) height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("JUMP!" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    glutKeyboardUpFunc(keyUp);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    glutSpecialUpFunc(keySpecialUp);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(1, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}