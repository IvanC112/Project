#include <iostream>
#include "Header_Files/Validate_Direction.hh"
using namespace std;

string ValidateMaze(string input) {
	
	while (input != "one" && input != "two") {
		cout << "That is not a valid input. Type either 'one' or 'two'" << endl;
		getline(cin, input);
	}
	
return input;
}