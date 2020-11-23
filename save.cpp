#include "save.h"

Save::Save()=default;

void Save::saveScore(int score) {

    ofstream outFile("../JumpScores.txt");

    if (outFile) {
        outFile << score;
        outFile << "\n";
    }

    outFile.close();
}