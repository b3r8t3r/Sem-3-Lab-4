#include "FracNum.h"
#include "IError.h"

int GCD(int x, int y) {
    return y ? GCD(y, x % y) : x;
}

FracNum::FracNum() : logger("FracNum", Enable) {
    Numerator = 0;
    Denominator = 1;
    Nod = 0;
}

FracNum::FracNum(double num, double denum) : logger("FracNum2", Enable) {

    try
    {
        if (denum == 0)
            throw MathIError("division by zero", num, denum, '/');
    }
    catch (MathIError& exception)
    {
        cerr << "ERROR: (" << exception.what() << ")\n";
        num = 0;
        denum = 1;
        abort();
        //return;
    }

    Numerator = num;
    /*try{
        Denominator = denum;
        if (!Denominator) throw invalid_argument("");
    }
    catch (invalid_argument) {
        cout << "Warning! Denomentor is equal 0! ";
        abort();
    }*/

    Denominator = denum;
    

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
    Logger a("Input", Enable);
    string num1, num2;
    try {
        if (&is == &cin)
            cout << "Numerator:\n: ";
        is >> num1;
        if (&is == &cin)
            cout << "Denominator:\n: ";
        is >> num2;
        
        

        for (int i = 0; i<num1.size();i++) {
            if ((num1[i] < 48 || num1[i]> 57) && (num1[i] != 43) && (num1[i] != 45)) {
                throw InputIError("input error","wrong char");
            }
        }
        for (int i = 0; i < num2.size(); i++) {
            if ((num2[i] < 48 || num2[i]> 57) && (num2[i] != 43) && (num2[i] != 45)) {
                throw InputIError("input error", "wrong char");
            }
        }
    }
    catch (InputIError& exception) {
        cerr << "ERROR: (" << exception.what() << ")\n";
        abort();
    }
    fn.Numerator = stoi(num1);
    fn.Denominator = stoi(num2);
    return is;
}

ostream& operator<<(ostream& os, const FracNum& fn) {
    Logger a("Output", Enable);
    os << fn.Numerator << "/" << fn.Denominator;
    return os;
}

FracNum& FracNum::operator= (const FracNum& fn) {
    Logger a("Define", Enable);
    Denominator = fn.Denominator;
    Numerator = fn.Numerator;
    return *this;
}

FracNum operator+(const FracNum& fn1, const FracNum& fn2) {
    Logger a("Addition", Enable);
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
    Logger a("Subtraction", Enable);
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
    Logger a("Multiplication", Enable);
    FracNum fn3(fn1.Numerator * fn2.Numerator, fn1.Denominator * fn2.Denominator);
    return fn3;
}

FracNum operator/(const FracNum& fn1, const FracNum& fn2) {
    Logger a("Division", Enable);
    FracNum fn3(fn1.Numerator * fn2.Denominator, fn1.Denominator * fn2.Numerator);
    return fn3;
}

FracNum operator^(const FracNum& fn, int power) {
    Logger a("Power", Enable);
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
    Logger a("More", Enable);
    int expr1 = fn1.Numerator * fn2.Denominator - fn2.Numerator * fn1.Denominator;
    int expr2 = fn1.Denominator * fn2.Denominator;
    return (expr1 > 0 && expr2 > 0 || expr1 < 0 && expr2 < 0);
}

bool operator>=(const FracNum& fn1, const FracNum& fn2) {
    Logger a("More or equal", Enable);
    int expr1 = fn1.Numerator * fn2.Denominator - fn2.Numerator * fn1.Denominator;
    int expr2 = fn1.Denominator * fn2.Denominator;
    return (expr1 >= 0 && expr2 > 0 || expr1 <= 0 && expr2 < 0);
}

bool operator==(const FracNum& fn1, const FracNum& fn2) {
    Logger a("Equal", Enable);
    return (fn1.Numerator == fn2.Numerator && fn1.Denominator == fn2.Denominator);
}

bool operator<(const FracNum& fn1, const FracNum& fn2) {
    Logger a("Less", Enable);
    int expr1 = fn1.Numerator * fn2.Denominator - fn2.Numerator * fn1.Denominator;
    int expr2 = fn1.Denominator * fn2.Denominator;
    return (expr1 < 0 && expr2>0 || expr1 > 0 && expr2 < 0);
}

bool operator<=(const FracNum& fn1, const FracNum& fn2) {
    Logger a("Less or equal", Enable);
    int expr1 = fn1.Numerator * fn2.Denominator - fn2.Numerator * fn1.Denominator;
    int expr2 = fn1.Denominator * fn2.Denominator;
    return (expr1 <= 0 && expr2 > 0 || expr1 >= 0 && expr2 < 0);
}