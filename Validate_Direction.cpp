#include <iostream>
#include "Header_Files/Validate_Direction.hh"
using namespace std;

string ValidateDirection(string input) {
	
	while (input != "north" && input != "east" && input != "west" && input != "status") {
		cout << "Type 'north', 'east', 'west', or 'status'" << endl;
		getline(cin, input);
	}
	
return input;
}