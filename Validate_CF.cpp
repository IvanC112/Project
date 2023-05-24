#include <iostream>
#include "Header_Files/Validate_CF.hh"
#include <limits>
using namespace std;

int ValidateCF(string input) {

	int cf;
	
	while (input != "heads" && input != "tails") {
			cout << "That is not a valid input. Type either 'heads' or 'tails'." << endl;
				cin >> input;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		if (input == "heads") {
			cf = 0;
		}
		else if (input == "tails") {
			cf = 1;
		}
	
return cf;
}