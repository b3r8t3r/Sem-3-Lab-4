#pragma once
#include <string>

using namespace std;

extern bool Enable;

class Logger {
public:
    bool enable;
    Logger(const string& str, const bool _enable = false);

    ~Logger();
    void OutFuctName(string name, const bool _enable);

    string nameClass;
};