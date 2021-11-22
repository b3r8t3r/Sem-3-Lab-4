#include "pch.h"
#include "framework.h"
#include "IError.h"

IError::~IError()
{
    ofstream f("error.txt", ios::app);
    f << "Error: " << m_IError << endl;
    f.close();
}

MathIError::MathIError(string error, int a, int b, char op) : IError(error) {
    m_mathIError = to_string(a) + " " + op + " " + to_string(b);
}

string MathIError::what() const noexcept {
    string error = m_IError + " : " + m_mathIError;
    return error;
}

InputIError::InputIError(string error, string inputtext) : IError(error) {
    m_inputIError = inputtext;
}

string InputIError::what() const noexcept {
    string error = m_IError + " : " + m_inputIError;
    return error;
}
