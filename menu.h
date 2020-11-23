//
// Created by Ben on 4/20/2018.
//

#ifndef BACKGROUND_MENU_H
#define BACKGROUND_MENU_H

class Menu {
    protected:

    /*//TEST//String for displayed menu text
        std::string menu = "MENU";
        std::string exit = "EXIT";
        std::string resume = "RESUME";
        std::string gameOver = "Game Over!";
        std::string saveGame = "SAVE GAME";
        std::string openGame = "OPEN GAME SAVE";*/


    public:

        /*Default Constructor
         * Requires: Nothing
         * Modifies: Nothing
         * Effects: Initiates the object
         */
        Menu();

        /*Draw Pause Menu Method
         * Requires: Nothing
         * Modifies: Nothing
         * Effects: Draw the pause menu
         */
        void drawPauseMenu() const;

        /*Draw Start Menu Method
         * Requires: Nothing
         * Modifies: Nothing
         * Effects: Draw the start menu
         */

        void drawStartMenu() const;

        /*Draw End Screen Method
         * Requires: Nothing
         * Modifies: Nothing
         * Effects: Draw the end menu
         */

        void drawEndScreen() const;

        /*Draw Screen Menu Method
         * Requires: Nothing
         * Modifies: Nothing
         * Effects: Draw screen menu
         */

        void drawScreenMenu() const;

        /*Draw Text method
         * Requires: message, font selection (1-7), red value 'r', green value 'g', blue value 'b', x coord, y coord
         * Modifies: File and score
         * Effects: Saves the users current score to the file
         */

        void drawText(std::string m,int font, double r,double g,double b,int xIn, int yIn);

    };


#endif //BACKGROUND_MENU_H
