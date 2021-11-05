#include "Game.h"

using namespace std;

FunnyGame::FunnyGame() /*: //Logger("FunnyGame")*/ {
	srand(time(0));
	int num = Start();
	GridsResize(num);
	RowFill(num);
	CheckDot(num);
	isWin(num);
}

int FunnyGame::Start() {
	//Logger a("Start");
	int choice = 0;
	cout << "Welcome to FunnyGame! \nYour goal is to guess the location of randomly generated points.\nThe number of points depends on the size of the field. \nFor example, if Grid is 5x5, the number of attempts is 5, the number of dots is 2 and you have to find only 1.\n\n";
	cout << "Select game difficulty:\n1. Tutorial (Grid 3x3).\n2. Easy (Grid 10x10).\n3. Average (Grid 15x15).\n4. Hard (Grid 20x20).\n: ";
	cin >> choice;
	if (choice == 123454321) CheatMode = true;
	while (choice < 1 || choice > 4) {
		cout << "Wrong difficulty. Please, try again:\n: ";
		cin >> choice;
	}

	switch (choice) {
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
	//Logger a("Start");
	Row.assign(num, vector<bool>(num));
	PRow.assign(num, vector<bool>(num));
}

void FunnyGame::RowFill(int num){
	//Logger a("RowFill");
	
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
	//Logger a("random");
	return (rand() % 2 == 0);
}

void FunnyGame::ShowPlayerGrid(int num) {
	//Logger a("ShowPlayerGrid");
	for (int i = 0; i < num; i++) {
		cout << "\t";
		for (int j = 0; j < num; j++) {
			cout << PRow[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void FunnyGame::ShowGrids(int num) {
	//Logger a("ShowGrids");
	for (int i = 0; i < num; i++) {
		cout << "\t";
		for (int j = 0; j < num; j++) {
			cout << Row[i][j] << " ";
		}
		cout << "\t";
		for (int j = 0; j < num; j++) {
			cout << PRow[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void FunnyGame::CheckDot(int num) {
	//Logger a("CheckDot");
	count = 0;
	for (int i = 0; i < num; i++) {
		if (!CheatMode) ShowPlayerGrid(num);
		else ShowGrids(num);
		int x = 0, y = 0;
		cout << "Enter X and Y coords:\n: ";

		do {
			cin >> x;
			cout << ": ";
			cin >> y;
			
			if ((x < 0) || (x >= num) || (y < 0) || (y >= num)) cout << "Coords are incorrect. Please, try again:\n: ";
			else if (PRow[y][x]) cout << "This coords are unavaliable. Please, try again:\n: ";
			else cout << "\n\n";
		} while ((x < 0) || (x >= num) || (y < 0) || (y >= num) || PRow[y][x]);

		PRow[y][x] = true;

		if (Row[y][x]) count++;
	}
}

bool FunnyGame::isWin(int num){
	//Logger a("isWin");
	ShowGrids(num);
	if (count>=(num/3)) { cout << "You won the game!\n"; return true; }
	else { cout << "You lose the game!\n"; return false; }
}