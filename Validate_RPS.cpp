#include <iostream>
#include "Header_Files/Validate_RPS.hh"
#include <limits>
using namespace std;

int ValidateRPS(string input) {

	int rps;
	while (input != "rock" && input != "paper" && input != "scissors") {
		cout << "That is not a valid input. Type either 'rock', 'paper', or 'scissors'." << endl;
			cin >> input;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	if (input == "rock") {
		rps = 0;
	}
	else if (input == "paper") {
		rps = 1;
	}
	else if (input == "scissors") {
		rps = 2;
	}
	
return rps;
}