#include "FracNum.h"

int GCD(int x, int y) {
    return y ? GCD(y, x % y) : x;
}

FracNum::FracNum() : logger("FracNum") {
    Numerator = 0;
    Denominator = 1;
    Nod = 0;
}

FracNum::FracNum(double num, double denum) : logger("FracNum2") {
    Numerator = num;
    try{
        Denominator = denum;
        if (!Denominator) throw invalid_argument("");
    }
    catch (invalid_argument) {
        cout << "Warning! Denomentor is equal 0! ";
        abort();
    }
    Nod = GCD(Numerator, Denominator);
    Numerator /= Nod;
    Denominator /= Nod;
    if (Denominator < 0) {
        Numerator*=-1;
        Denominator*=-1;
    }
}

FracNum::~FracNum() {
    Numerator = 0;
    Denominator = 0;
    Nod = 0;

}

istream& operator>>(istream& is, FracNum& fn) {
    Logger a("Input");
    is >> fn.Numerator;
    is >> fn.Denominator;
    return is;
}

ostream& operator<<(ostream& os, const FracNum& fn) {
    Logger a("Output");
    os << fn.Numerator << "/" << fn.Denominator;
    return os;
}

FracNum& FracNum::operator= (const FracNum& fn) {
    Logger a("Define");
    Denominator = fn.Denominator;
    Numerator = fn.Numerator;
    return *this;
}

FracNum operator+(const FracNum& fn1, const FracNum& fn2) {
    Logger a("Addition");
    if (fn1.Denominator == fn2.Denominator) {
        FracNum fn3(fn1.Numerator + fn2.Numerator, fn1.Denominator);
        return fn3;
    }
    else {
        FracNum fn3((fn1.Numerator * fn2.Denominator) + (fn2.Numerator * fn1.Denominator), fn1.Denominator * fn2.Denominator);
        return fn3;
    }
}

FracNum operator-(const FracNum& fn1, const FracNum& fn2) {
    Logger a("Subtraction");
    if (fn1.Denominator == fn2.Denominator) {
        FracNum fn3(fn1.Numerator - fn2.Numerator, fn1.Denominator);
        return fn3;
    }
    else {
        FracNum fn3((fn1.Numerator * fn2.Denominator) - (fn2.Numerator * fn1.Denominator), fn1.Denominator * fn2.Denominator);
        return fn3;
    }
}

FracNum operator*(const FracNum& fn1, const FracNum& fn2) {
    Logger a("Subtraction");
    FracNum fn3(fn1.Numerator * fn2.Numerator, fn1.Denominator * fn2.Denominator);
    return fn3;
}

FracNum operator/(const FracNum& fn1, const FracNum& fn2) {
    Logger a("Division");
    FracNum fn3(fn1.Numerator * fn2.Denominator, fn1.Denominator * fn2.Numerator);
    return fn3;
}

FracNum operator^(const FracNum& fn, int power) {
    Logger a("Power int");
    if (!power) {
        FracNum fn3(1,1);
        return fn3;
    }
    else if (power == -1) {
        FracNum fn3(fn.Denominator,fn.Numerator);
        return fn3;
    }
    else if (power < -1) {
        FracNum fn3(pow(fn.Denominator,abs(power)), pow(fn.Numerator, abs(power)));
        return fn3;
    }
    else {
        FracNum fn3(pow(fn.Numerator, power), pow(fn.Denominator, power));
        return fn3;
    }
}



bool operator>(const FracNum& fn1, const FracNum& fn2) {
    Logger a("More");
    int expr1 = fn1.Numerator * fn2.Denominator - fn2.Numerator * fn1.Denominator;
    int expr2 = fn1.Denominator * fn2.Denominator;
    return (expr1 > 0 && expr2 > 0 || expr1 < 0 && expr2 < 0);
}

bool operator>=(const FracNum& fn1, const FracNum& fn2) {
    Logger a("More or equal");
    int expr1 = fn1.Numerator * fn2.Denominator - fn2.Numerator * fn1.Denominator;
    int expr2 = fn1.Denominator * fn2.Denominator;
    return (expr1 >= 0 && expr2 > 0 || expr1 <= 0 && expr2 < 0);
}

bool operator==(const FracNum& fn1, const FracNum& fn2) {
    Logger a("Equal");
    return (fn1.Numerator == fn2.Numerator && fn1.Denominator == fn2.Denominator);
}

bool operator<(const FracNum& fn1, const FracNum& fn2) {
    Logger a("Less");
    int expr1 = fn1.Numerator * fn2.Denominator - fn2.Numerator * fn1.Denominator;
    int expr2 = fn1.Denominator * fn2.Denominator;
    return (expr1 < 0 && expr2>0 || expr1 > 0 && expr2 < 0);
}

bool operator<=(const FracNum& fn1, const FracNum& fn2) {
    Logger a("Less or equal");
    int expr1 = fn1.Numerator * fn2.Denominator - fn2.Numerator * fn1.Denominator;
    int expr2 = fn1.Denominator * fn2.Denominator;
    return (expr1 <= 0 && expr2 > 0 || expr1 >= 0 && expr2 < 0);
}