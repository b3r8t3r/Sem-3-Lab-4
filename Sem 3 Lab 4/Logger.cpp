#include <iostream>
#include <string>
#include "Logger.h"

using namespace std;

Logger::Logger(const string& str) : nameClass(str) {
    cout << endl << "Construct " << str << endl;
}

Logger::~Logger() {
    cout << endl << "Destruct " << nameClass << endl;
}

void Logger::OutFuctName(string name) {
    cout << "Function " << name << " begin to work." << endl;
}