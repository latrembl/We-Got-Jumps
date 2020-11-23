//
// Created by Ben on 4/17/2018.
//

#ifndef GRAPHICS_PLAYERCLASS_H
#define GRAPHICS_PLAYERCLASS_H


#include "shapes.h"
#include "stage.h"

class playerClass: public Stage {
protected:
    int score;
    int xVelocity;
    int yVelocity;
    bool onStage;
public:
    bool isOnStage() const;

    void setOnStage(bool onStage);

    int getXVelocity() const;

    void setXVelocity(int xVelocity);

    int getYVelocity() const;

    void setYVelocity(int yVelocity);

    int getDeltaMovement() const;

    void setDeltaMovement(int deltaMovement);

    Rect playerIcon;

    const Rect &getPlayerIcon() const;

    void setPlayerIcon(const Rect &playerIcon);

    /*Default Constructor
     *Requires: Nothing
     * Modifies: Set the location of the player object to the default location
     * Effects: The location of the player object on the users screen
     */
    playerClass();

    /*Constructor(With x and y locations of the player object)
     * Requires: X and Y int values
     * Modifies: The values for the x and y location of the player object
     * Effects: The location of the player object
     */
    playerClass(int x, int y);

    /*Constructor(With x and y locations and the players score)
     * Requires: The X and Y values and an int for the score
     * Effects: The values for the x, y and score of the player
     * Modifies: THe location and score of the player object
     */
    playerClass(int x, int y, int score);

    int getScore() const;

    void setScore(int score);

    /*Move Method
     * Requires: Nothing
     * Modifies: The location values for the shape
     * Effects: The location of the player object on the users screen
     */
    void move(int moveX, int moveY);

    /*Draw method
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Displays the user object
     */

    void draw() override;


    /*Jump Method
     * Requires: Nothing
     * Modifies: The Y of the player object
     * Effects: The location of the player object
     */
    void jump();

    /*Increase Score Method
     * Requires: Nothing
     * Modifies: The score field
     * Effects: The score shown to the user
     */
    void addScore();

    /*Reset Score Method
     * Requires: Nothing
     * Modifies: Resets the score value
     * Effects: Resets the value of the score for the player object
     */
    void resetScore();

};


#endif //GRAPHICS_PLAYERCLASS_H
