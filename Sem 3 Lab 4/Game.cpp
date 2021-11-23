#include "Game.h"
#include "IError.h"

using namespace std;

FunnyGame::FunnyGame() : logger("FunnyGame", Enable) {
	srand(time(0));
	Difficulty = Start();
	GridsResize(Difficulty);
	RowFill(Difficulty);
	CheckDot(Difficulty);
	isWin(Difficulty);
}

int FunnyGame::Start() {
	Logger a(" Start", Enable);
	string choice;
	cout << "Welcome to FunnyGame! \nYour goal is to guess the location of randomly generated points.\nThe number of points depends on the size of the field. \nFor example, if Grid is 5x5, the number of attempts is 5, the number of dots is 2 and you have to find only 1.\n\n";
	cout << "Select game difficulty:\n1. Tutorial (Grid 3x3).\n2. Easy (Grid 10x10).\n3. Average (Grid 15x15).\n4. Hard (Grid 20x20).\n: ";
	try {

		cin >> choice;
		if (choice == "123454321") CheatMode = true;
		for (int i = 0; i < choice.size(); i++)
			if (choice[i] < 48 || choice[i]> 57) throw InputIError("input error", "wrong char");
			else if ((choice != "1") && (choice != "2") && (choice != "3") && (choice != "4")) throw InputIError("input error", "wrong variant");

	}

	catch (InputIError& exception) {
		cerr << "ERROR: (" << exception.what() << ")\n";
		while (true) {

			cout << "You're entered the number of variant incorrectly. Please, try again:\n: ";
			cin >> choice;
			if ((choice == "1") || (choice == "2") || (choice == "3") || (choice == "4")) break;
		}
	}

	switch (stoi(choice)) {
	case 1: {
		return TUTORIAL;
	}
	case 2: {
		return EASY;
	}
	case 3: {
		return AVERAGE;
	}
	case 4: {
		return HARD;
	}
	}
}

void FunnyGame::GridsResize(int num) {
	Logger a(" Start", Enable);
	Row.assign(num, vector<bool>(num));
	PRow.assign(num, vector<bool>(num));
}

void FunnyGame::RowFill(int num){
	Logger a(" RowFill", Enable);
	
	int x = 0,y = 0;
	for (int i = 0; i < num / 2; i++) {
		do {
		x = rand() % (num);
		y = rand() % (num);
		} while (Row[x][y]);
		Row[x][y] = true;
	}


}

bool FunnyGame::random() {
	Logger a(" random", Enable);
	return (rand() % 2 == 0);
}

void FunnyGame::ShowPlayerGrid(int num) {
	Logger a(" ShowPlayerGrid", Enable);
	
	cout << endl << "\t\t ";

	
	for (int i = 0;i<num;i++) cout << i << " ";
	cout << endl << "\t\t ";
	
	for (int i=0;i<num;i++) cout << ((i<10)?"— ":"—— ");

	cout << endl;
	for (int i = 0; i < num; i++) {
		cout << "\t" << i << "\t|";
		for (int j = 0; j < num; j++) {
			cout << PRow[i][j] << ((j < 9)?" ":"  ");
		}
		cout << endl;
	}
	cout << endl << endl;
}

void FunnyGame::ShowGrids(int num) {
	Logger a(" ShowGrids", Enable);

	cout << endl << "\t\t ";

	for (int i = 0; i < num; i++) cout << i << " ";

	cout << "\t   \t ";
	
	for (int i = 0; i < num; i++) cout << i << " ";

	cout << endl << "\t\t ";

	for (int i = 0; i < num; i++) cout << ((i < 10) ? "— " : "—— ");

	cout << "\t   \t ";

	for (int i = 0; i < num; i++) cout << ((i < 10) ? "— " : "—— ");

	cout << endl;
	for (int i = 0; i < num; i++) {
		cout << "\t" << i << "\t|";
		for (int j = 0; j < num; j++) {
			cout << Row[i][j] << ((j < 9) ? " " : "  ");
		}
		cout << "\t  " << i << "\t|";
		for (int j = 0; j < num; j++) {
			cout << PRow[i][j] << ((j < 9) ? " " : "  ");
		}
		cout << endl;
	}
	cout << endl << endl;
}

void FunnyGame::CheckDot(int num) {
	Logger a(" CheckDot", Enable);
	count = 0;
	for (int i = 0; i < num; i++) {
		if (!CheatMode) ShowPlayerGrid(num);
		else ShowGrids(num);
		string x = "", y = "";
		

		try {
			cout << "Enter X and Y coords:\nX: ";
			cin >> x;
			cout << "Y: ";
			cin >> y;
			for (int i = 0; i < x.size(); i++)
				if (x[i] < 48 || x[i]> 57) throw InputIError("input error", "wrong char");
			
			
			for (int i = 0; i < y.size(); i++)
				if (y[i] < 48 || y[i]> 57) throw InputIError("input error", "wrong char");

			if ((stoi(x) < 0) || (stoi(x) >= num)|| (stoi(y) < 0) || (stoi(y) >= num)) InputIError("input error", "wrong coords");
			else if (PRow[stoi(y)][stoi(x)]) InputIError("input error", "occupied coords");
		}

		catch (InputIError& exception) {
			cerr << "ERROR: (" << exception.what() << ")\n";
			while (true) {
				cout << "You're entered the coords incorrectly. Please, try again:\n: ";
				cin >> x;
				cout << ": ";
				cin >> y;
				cout << endl;
				if ((stoi(x) >= 0) && (stoi(x) < num)&& (stoi(y) >= 0) && (stoi(y) < num)&&!PRow[stoi(y)][stoi(x)]) break;
			}
		}

		PRow[stoi(y)][stoi(x)] = true;

		if (Row[stoi(y)][stoi(x)]) count++;
	}
}

bool FunnyGame::isWin(int num){
	Logger a(" isWin", Enable);
	ShowGrids(num);
	if (count>=(num/3)) { cout << "You won the game!\n"; return true; }
	else { cout << "You lose the game!\n"; return false; }
}