#include <iostream>
#include "Header_Files/Make_Lowercase.hh"
using namespace std;

string MakeLowercase(string input) {
  
	for (unsigned int i = 0; i < input.size(); i++) {
    input.at(i) = tolower(input.at(i));
  }
  return input;
}