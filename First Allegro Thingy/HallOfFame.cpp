#include "HallOfFame.h"

void HallOfFame::readFile()
{
    std::ifstream inputFile("HallOfFame.txt"); //reads the file and puts the scores in the vector
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
    scores.push_back(sc); //adds the new score
    sort(scores.begin(), scores.end(),greater<int>());  //reorganizes the score vector in descending order
}

vector<int> HallOfFame::getScores()
{
    return scores; //returns the scores
}

void HallOfFame::writeFile()
{
    std::ofstream outputFile("HallOfFame.txt"); //writes the scores in the file
    if (outputFile.is_open()) {
        for (int sc : scores) {
            outputFile << sc << endl;
        }
    }
        outputFile.close();
}

