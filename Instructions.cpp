#include <iostream>
#include "Header_Files/Instructions.hh"
using namespace std;

void Instructions() {
  
	string instructionsPath;
	
	cout << "Would you like instructions?" << endl;
	cout << "Type 'yes' or 'no'." << endl;
	cout << endl;
  
	getline(cin, instructionsPath);

	if (instructionsPath == "yes") {
		cout << endl;
		cout << "Throughout your adventure, I will serve as your guide narrating what happens." << endl;
		cout << "You will direct me for what action should be taken by inputting commands when prompted." << endl;
		cout << endl;
		cout << "Well then, let's get started!\n" << endl;
	}
	else if (instructionsPath == "no") {
		cout << endl;
    cout << "Well then, let's get started!" << endl;
		cout << endl;
  }
	else {
		cout << endl;
		cout << "This is not a valid input. Type either 'yes' or 'no'." << endl;
		Instructions();
	}
}