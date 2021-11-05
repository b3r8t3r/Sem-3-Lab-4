#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#include "Logger.h"

using namespace std;

const int TUTORIAL = 3;
const int EASY = 10;
const int AVERAGE = 15;
const int HARD = 20;

class FunnyGame {
private:
	vector< vector <bool> > Row , PRow;
	int Difficulty;
	int count;
	bool CheatMode;
public:
	//Logger logger;
	FunnyGame();
	int Start();
	void GridsResize(int num);
	void RowFill(int num);
	bool random();
	void ShowPlayerGrid(int num);
	void ShowGrids(int num);
	void CheckDot(int num);
	bool isWin(int num);
};

