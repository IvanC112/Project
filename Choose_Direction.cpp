#include <iostream>
#include "Header_Files/Global_Variables.hh"
#include "Header_Files/East_Dungeon.hh"
#include "Header_Files/North_Dungeon.hh"
#include "Header_Files/West_Dungeon.hh"
#include "Header_Files/Dungeons_Beaten.hh"
#include "Header_Files/Make_Lowercase.hh"
#include "Header_Files/Choose_Direction.hh"
#include "Header_Files/Validate_Direction.hh"
using namespace std;

void ChooseDirection() {
	cout << endl;
	cout << "Where should we check?" << endl;
	cout << "Type either 'north', 'east', or 'west'." << endl;
	cout << "(If you'd like to see your progress type 'status')" << endl;
	
	string dungeonChoice;

	getline(cin, dungeonChoice);

	while (dungeonChoice != "north" && dungeonChoice != "east" && dungeonChoice != "west" && dungeonChoice != "status") {
		cout << "That is not a valid input. Type 'north', 'east', or 'west'" << endl;
		getline(cin, dungeonChoice);
	}	

	//Calls each dungeon's function unless it's been beaten already
	while (dungeonChoice == "north" || dungeonChoice == "east" || dungeonChoice == "west" || dungeonChoice == "status") {
		
		if (dungeonChoice == "north" && northDung == true) {
			cout << "We've already defeated the monster there!" << endl;
		}
		else if (dungeonChoice == "north" && northDung == false) {
			NorthDungeon();
		}
		
		if (dungeonChoice == "east" && eastDung == true) {
			cout << "We've already defeated the monster there!" << endl;
		}
    else if (dungeonChoice == "east" && eastDung == false) {
			EastDungeon();
		}
		
		if (dungeonChoice == "west" && westDung == true) {
			cout << "We've already defeated the monster there!" << endl;
		}
		else if (dungeonChoice == "west" && westDung == false) {
			WestDungeon();
		}
		
		if (dungeonChoice == "status") {
			DungeonsBeaten();
		}

		if (dungeonsBeaten == 3) {
			break;
		}
		
		cout << endl;
		cout << "Where should we head next? Type 'north', 'east', 'west' or 'status'" << endl;

		getline(cin, dungeonChoice);
		dungeonChoice = ValidateDirection(dungeonChoice);
	}
}