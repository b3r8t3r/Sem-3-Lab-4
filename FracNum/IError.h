#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class IError {
protected:
    string m_IError;
public:
    IError(string error) : m_IError(error) {}
    string what() const noexcept
    {
        return m_IError;
    }

    ~IError();

};

class MathIError : public IError {
private:
    string m_mathIError;
public:
    MathIError(string error, int a, int b, char op);

    string what() const noexcept;
};

class InputIError : public IError {
private:
    string m_inputIError;
public:
    InputIError(string error, string inputtext);

    string what() const noexcept;

};