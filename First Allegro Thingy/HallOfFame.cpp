#include "HallOfFame.h"

void HallOfFame::readFile()
{
    std::ifstream inputFile("HallOfFame.txt");
    if (inputFile.is_open()) {
        int readNumber;
        while (inputFile >> readNumber) {
            scores.push_back(readNumber);
        }
    }
        inputFile.close();
        
}

void HallOfFame::addHScore(int sc)
{
    scores.push_back(sc);
    sort(scores.begin(), scores.end(),greater<int>()); 
}

vector<int> HallOfFame::getScores()
{
    return scores;
}

void HallOfFame::writeFile()
{
    std::ofstream outputFile("HallOfFame.txt");
    if (outputFile.is_open()) {
        for (int sc : scores) {
            outputFile << sc << endl;
        }
    }
        outputFile.close();
}

