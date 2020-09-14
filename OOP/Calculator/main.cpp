//============================================================================
// Name        : Calculator.cpp
// Author      : 21118_Shubham
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Calculator {
private:
	int a, b;
	int choice;
public:
	void getInput() {
		cout << "\n\nEnter two numbers: ";
		cin >> a >> b;
	}
	void getChoice() {
		cout << "Enter\n 1 for addition\n 2 for substraction\n 3 for multiplication\n 4 for division\n";
		cin >> choice;
	}
	void displayResult() {
		switch (choice) {
		case 1 :
			cout << "Addition is : " << a + b << endl;
			break;
		case 2 :
			cout << "Substraction is : " << a - b << endl;
			break;
		case 3 :
			cout << "Multiplication is : " << a * b << endl;
			break;
		case 4 :
			if (b == 0) cout << "ERROR : Invalid input for division\n";
			else {
				cout << "Division is : " << (a * 0.1) / b << endl;
			}
		}
	}
};

int main() {
	bool flag;
	do {
        Calculator operation;
        operation.getInput();
        operation.getChoice();
        operation.displayResult();
        cout << "\n\nEnter 1 for another operation and 0 to exit the program : ";
        cin >> flag;
	}
	while (flag);
	return 0;
}
