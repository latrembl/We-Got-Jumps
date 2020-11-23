#ifndef SAVE_SAVE_H
#define SAVE_SAVE_H

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

class Save {

private:
    int privateScore;
public:
    Save();
    void saveScore(int score);
};

#endif //SAVE_SAVE_H
