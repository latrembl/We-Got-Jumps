//
// Created by andrew hollar on 4/25/18.
//

#include "shapes.h"
#include "stage.h"
#ifndef FINALPROJECT120_PLATFORM_H
#define FINALPROJECT120_PLATFORM_H
class Platform : public Stage {
private:

public:
    Rect platformDisplay;
    bool hasBeenLandedOn;

    bool isHasBeenLandedOn() const;

    void setHasBeenLandedOn(bool hasBeenLandedOn);

    Platform();
    Platform(int y);
    Platform(int x, int y);
    Platform(int x, int r, int g, int b);
    Platform(int x, int y, int r, int g, int b);

    void setPlatformDisplay(Rect platform);

    Rect getPlatformDisplay() const;
    void draw() override;
    void move(int x, int y);
};
#endif //FINALPROJECT120_PLATFORM_H
