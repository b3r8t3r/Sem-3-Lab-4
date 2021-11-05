#include <iostream>
#include <math.h>
#include <vector>

#include "FracNum.h"
#include "Game.h"

using namespace std;

void FracNumTest() {
	FracNum a{ 3,-4 }, b{ 1,2 };
	int x = -5;
	cout << a << endl;
	cout << b << endl;
	cout << x << endl;
	cout << "(a+b) = " << (a + b) << endl;
	cout << "(a-b) = " << (a - b) << endl;
	cout << "(a*b) = " << (a * b) << endl;
	//cout << "(a^b) = " << (a ^ b) << endl;
	cout << "(a^x) = " << (a ^ x) << endl;
	cout << "(b^x) = " << (b ^ x) << endl;
	FracNum c = a;
	cout << "(a=b) = " << (a = b) << endl;
	a = c;
	cout << "(a>b) = " << (a > b) << endl;
	cout << "(a>=b) = " << (a >= b) << endl;
	cout << "(a==b) = " << (a == b) << endl;
	cout << "(a<=b) = " << (a <= b) << endl;
	cout << "(a<b) = " << (a < b) << endl;
}

int main(){
	
	//FracNumTest();
	FunnyGame a;
	//cout << pow(4,-1) << endl;

}