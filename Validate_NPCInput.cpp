#include <iostream>
#include "Header_Files/Validate.NPCInput.hh"
using namespace std;

string ValidateNPCInput(string input) {

  while (input != "one" && input != "two" && input != "three" && input != "no") {
		cout << "That is not a valid input. Please type either 'one' for the Blacksmith, 'two' for the Butcher, 'three' for the Guard, or 'no' for none." << endl;
		getline(cin, input);
	}

  return input;
  
}