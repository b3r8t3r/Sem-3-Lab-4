#pragma once
#include <string>

using namespace std;

class Logger {
public:
    Logger(const string& str);

    ~Logger();
    void OutFuctName(string name);

    string nameClass;
};