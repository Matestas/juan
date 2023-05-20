#include "HallOfFame.h"

void HallOfFame::readFile()
{
    std::ifstream inputFile("HallOfFame.txt");
    if (inputFile.is_open()) {
        int readNumber;
        while (inputFile >> readNumber) {
            score.push_back(readNumber);
        }
    }
        inputFile.close();
        
}

void HallOfFame::addHScore(int sc)
{
    score.push_back(sc);
    sort(score.begin(), score.end(),greater<int>()); 
}

vector<int> HallOfFame::getScores()
{
    return score;
}

void HallOfFame::writeFile()
{
    std::ofstream outputFile("HallOfFame.txt");
    if (outputFile.is_open()) {
        for (int sc : score) {
            outputFile << sc << endl;
        }
    }
        outputFile.close();
}

