// Logger.cpp : Определяет функции для статической библиотеки.
//
#include "pch.h"
#include "framework.h"
#include <iostream>
#include <string>
#include "Logger.h"

using namespace std;

bool Enable = false;

Logger::Logger(const string& str, const bool _enable) : nameClass(str, _enable) {
    enable = _enable;
    if (enable) cout << endl << "Construct " << str << endl;
}

Logger::~Logger() {
    if (enable) cout << endl << "Destruct " << nameClass << endl;
}

void Logger::OutFuctName(string name, const bool _enable) {
    if (_enable) cout << "Function " << name << " begin to work." << endl;
}