#pragma once
#include <math.h>

#include <iostream>
#include <vector>

#include "Logger.h"

using namespace std;

int GCD(int x, int y);  //Нахождение НОД

class FracNum {  //Класс работы с дробями
 private:
  double Numerator;    //Числитель
  double Denominator;  //Знаменатель
  double Nod;          //НОД (наибольшй общий делитель)
 public:
  Logger logger;
  FracNum();
  FracNum(double num, double denum);
  ~FracNum();
  //Операторы ввода и вывода
  friend istream& operator>>(istream& is, FracNum& fn);
  friend ostream& operator<<(ostream& os, const FracNum& fn);
  //Арифметические операторы
  friend FracNum operator+(const FracNum& fn1, const FracNum& fn2);
  friend FracNum operator-(const FracNum& fn1, const FracNum& fn2);
  friend FracNum operator*(const FracNum& fn1, const FracNum& fn2);
  friend FracNum operator/(const FracNum& fn1, const FracNum& fn2);
  friend FracNum operator^(const FracNum& fn, const int& power);

  friend FracNum operator+(const FracNum& fn, const int& inc);
  friend FracNum operator-(const FracNum& fn, const int& dec);
  friend FracNum operator*(const FracNum& fn, const int& mul);
  friend FracNum operator/(const FracNum& fn, const int& div);

  FracNum& operator=(const FracNum& fn1);
  //Логичекие операторы
  friend bool operator>(const FracNum& fn1, const FracNum& fn2);
  friend bool operator>=(const FracNum& fn1, const FracNum& fn2);
  friend bool operator==(const FracNum& fn1, const FracNum& fn2);
  friend bool operator!=(const FracNum& fn1, const FracNum& fn2);
  friend bool operator<=(const FracNum& fn1, const FracNum& fn2);
  friend bool operator<(const FracNum& fn1, const FracNum& fn2);
};

istream& operator>>(istream& is, FracNum& fn);
ostream& operator<<(ostream& os, const FracNum& fn);

FracNum operator+(const FracNum& fn1, const FracNum& fn2);
FracNum operator-(const FracNum& fn1, const FracNum& fn2);
FracNum operator*(const FracNum& fn1, const FracNum& fn2);
FracNum operator/(const FracNum& fn1, const FracNum& fn2);
FracNum operator^(const FracNum& fn, const int& power);

FracNum operator+(const FracNum& fn, const int& inc);
FracNum operator-(const FracNum& fn, const int& dec);
FracNum operator*(const FracNum& fn, const int& mul);
FracNum operator/(const FracNum& fn, const int& div);

bool operator>(const FracNum& fn1, const FracNum& fn2);
bool operator>=(const FracNum& fn1, const FracNum& fn2);
bool operator==(const FracNum& fn1, const FracNum& fn2);
bool operator!=(const FracNum& fn1, const FracNum& fn2);
bool operator<(const FracNum& fn1, const FracNum& fn2);
bool operator<=(const FracNum& fn1, const FracNum& fn2);