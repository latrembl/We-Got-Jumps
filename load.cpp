#include "load.h"

load::load()=default;

int load::loadScore() {

    fstream file("../jumpScores.txt");
    int score;
    file >> score;

    file.close();

    return score;
}