#pragma once
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include <Logger.h>
#include <IError.h>

using namespace std;

const int TUTORIAL = 3;
const int EASY = 10;
const int AVERAGE = 15;
const int HARD = 20;

class FunnyGame {
 private:
  vector<vector<bool> > Row, PRow;
  int Difficulty;  //Переменная, отвечающая за сложность
  int count;
  bool CheatMode;

 public:
  Logger logger;
  FunnyGame();  //Инициализация игры
  int Start();  //
  void GridsResize(int num);
  void RowFill(int num);
  bool random();
  void ShowPlayerGrid(int num);
  void ShowGrids(int num);
  void CheckDot(int num);
  bool isWin(int num);  //Функция для определения победы
};
