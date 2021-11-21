#include <iostream>
#include <math.h>
#include <vector>

#include "FracNum.h"
#include "Game.h"
#include "IError.h"
#include "Logger.h"

using namespace std;

void FracNumTest() {
	FracNum a, b;
	cin >> a;
	cin >> b;
	int x = -5;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "x = " << x << endl;
	cout << "(a+b) = " << (a + b) << endl;
	cout << "(a-b) = " << (a - b) << endl;
	cout << "(a*b) = " << (a * b) << endl;
	cout << "(a/b) = " << (a / b) << endl;

	cout << "(a+x) = " << (a + x) << endl;
	cout << "(a-x) = " << (a - x) << endl;
	cout << "(a*x) = " << (a * x) << endl;
	cout << "(a/x) = " << (a / x) << endl;

	cout << "(b+x) = " << (b + x) << endl;
	cout << "(b-x) = " << (b - x) << endl;
	cout << "(b*x) = " << (b * x) << endl;
	cout << "(b/x) = " << (b / x) << endl;

	cout << "(a^x) = " << (a ^ x) << endl;
	cout << "(b^x) = " << (b ^ x) << endl;
	cout << "(a^-1) = " << (a ^ -1) << endl;
	cout << "(b^-1) = " << (b ^ -1) << endl;
	FracNum c = a;
	cout << "(a=b) = " << (a = b) << endl;
	a = c;
	cout << "(a>b) = " << (a > b) << endl;
	cout << "(a>=b) = " << (a >= b) << endl;
	cout << "(a==b) = " << (a == b) << endl;
	cout << "(a!=b) = " << (a != b) << endl;
	cout << "(a<=b) = " << (a <= b) << endl;
	cout << "(a<b) = " << (a < b) << endl;
}

int main(){

	setlocale(LC_ALL, "Rus");
	Logger main("main");
	cout << "Выберите, включить ли логгер для программы или нет:\n1. Да.\n2. Нет.\n: ";
	string _choice;
	try {
		
		cin >> _choice;
		for (int i = 0; i<_choice.size();i++)
			if (_choice[i] < 48 || _choice[i]> 57) throw InputIError("input error", "wrong char");
			else if ((_choice != "1") && (_choice != "2")) throw InputIError("input error", "wrong variant");
			
	}

	catch (InputIError& exception) {
		cerr << "ERROR: (" << exception.what() << ")\n";
		while (true) {

			cout << "Вы неверно ввели номер варианта. Повторите попытку:\n: ";
			cin >> _choice;
			if ((_choice == "1") || (_choice == "2")) break;
		}
	}

	switch (stoi(_choice)) {
	case 1: {
		Enable = 1;
		break;
		}
		  default: {
			  break;
		}
	}
	
	cout << "\nВыберите, какое задание включить:\n1. Работа с дробями.\n2. Игра.\n: ";
	try {

		cin >> _choice;
		for (int i = 0; i < _choice.size(); i++)
			if (_choice[i] < 48 || _choice[i]> 57) throw InputIError("input error", "wrong char");
			else if ((_choice != "1") && (_choice != "2")) throw InputIError("input error", "wrong variant");
	}

	catch (InputIError& exception) {
		cerr << "ERROR: (" << exception.what() << ")\n";
		while (true) {

			cout << "Вы неверно ввели номер варианта. Повторите попытку:\n: ";
			cin >> _choice;
			if ((_choice == "1") || (_choice == "2")) break;
		}
	}

	switch (stoi(_choice)) {
	case 1: {
		FracNumTest();
		break;
	}
	default: {
		FunnyGame Game;
	}
	}

}