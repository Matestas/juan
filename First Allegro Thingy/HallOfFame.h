#pragma once
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
class HallOfFame
{
private:
	vector<int>scores;
public:
	void readFile();
	void addHScore(int);
	void writeFile();
	vector<int> getScores();
};

