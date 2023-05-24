#include <iostream>
#include <limits>
#include "Header_Files/West_Dungeon.hh"
#include "Header_Files/Global_Variables.hh"
#include "Header_Files/Make_Lowercase.hh"
#include "Header_Files/Validate_Maze.hh"
#include "Header_Files/Validate_CF.hh"
#include "Classes/Bosses.hh"
using namespace std;

void WestDungeon() {

	cout << endl;
	cout << "This trail leads to some sort of cave. Let's go inside, we could find some clues about the monster the Village Chief spoke of." << endl;
	cout << endl;

  string passage1;
  string passage2;

	//Creates a maze with correct path ONE ONE

	while (passage1 != "one" && passage2 != "one") {
		cout << "The cave splits into two. We should try one of these paths, let's hurry!" << endl;
		cout << "Type either 'one' for left or 'two' for right" << endl;
		getline(cin, passage1);
		passage1 = ValidateMaze(passage1);

		if (passage1 == "one") {
			cout << "Seems like you made it to another fork in the road, do we go left or right?\nType 'one' or 'two'." << endl;
			getline(cin, passage2);
			passage2 = ValidateMaze(passage2);
			if (passage2 == "one") {
				break;
			}
			else if (passage2 == "two") {
				cout << "You seem to be back at the starting point!" << endl;
				passage1 = "";
				passage2 = "";
				continue;
			}
		}	
		 
		if (passage1 == "two") {
			cout << "Seems like you made it to another fork in the road, do we go left or right?\nType 'one' or 'two'." << endl;
			getline(cin, passage2);
			passage2 = ValidateMaze(passage2);
			cout << "You seem to be back at the starting point!" << endl;
			passage1 = "";
			passage2 = "";
			continue;
		}
  }

	cout << "\nLook at that! It's a Cyclops!\n" << endl;

	Boss Cyclops;
  Cyclops.SetName("Cyclops");
  Cyclops.SetHealth(3);
  Cyclops.SetDialogue("Cyclops: What's this? A human! AHHAHAHH I'm feeling hungry! Come now, let us have a friendly game of coin flip!");

	cout << "	       _......._" << endl;
	cout << "       .-'.'.'.'.'.'.`-." << endl;
	cout << "     .'.'.'.'.'.'.'.'.'.`." << endl;
	cout << "    /.'.'               '.\\" << endl;
	cout << "    |.'    _.--...--._     |" << endl;
	cout << "    \\    `._.-.....-._.'   /" << endl;
	cout << "    |     _..- .-. -.._   |" << endl;
	cout << " .-.'    `.   ((@))  .'   '.-." << endl;
	cout << "( ^ \\      `--.   .-'     / ^ )" << endl;
  cout << " \\  /         .   .       \\  /" << endl;
  cout << " /          .'     '.  .-    \\" << endl;
  cout << "( _.\\    \\ (_`-._.-'_)    /._\\)" << endl;
  cout << " `-' \\   ' .--.          / `-'" << endl;
  cout << "     |  / /|_| `-._.'\\   |" << endl;
  cout << "     |   |       |_| |   /-.._" << endl;
  cout << " _..-\\   `.--.______.'  |" << endl;
  cout << "      \\       .....     |" << endl;
  cout << "       `.  .'      `.  /" << endl;
  cout << "         \\           .'" << endl;
  cout << "          `-..___..-`" << endl;
  
  Cyclops.PrintDialogue();

  cout << "\nLets defeat him!" << endl;

  srand(time(0));

	string userInputString;
  int userInput;
	int userHealth = 4;
	int cyclopsInput;

  // 0 = HEADS
  // 1 = TAILS
	
  while (userHealth > 0 && Cyclops.GetHealth() > 0) {
		
    cyclopsInput = rand() % 2;
    cout << "\nWhat will you pick? Type either 'heads' or 'tails'." << endl;
    cin >> userInputString;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		userInput = ValidateCF(userInputString);

    if (cyclopsInput == 0 && userInput == 0 || cyclopsInput == 1 && userInput == 1) {
      cout << "Cyclops: You got lucky... It won't happen again!" << endl;
      Cyclops.LowerHealth();
    }

    else if (cyclopsInput == 0 && userInput == 1) {
			cout << "Cyclops: AHAHHA WRONG. It was Heads fool! Can you keep going?" << endl;
			userHealth--;
		}
		else if (cyclopsInput == 1 && userInput == 0) {
      cout << "Cyclops: AHAHHA WRONG. It was Tails fool! Can you keep going?" << endl;
      userHealth--;
    }
		
  }

  if (userHealth == 0) {
    cout << "\n\nYou begin to lose your strength. You blacked out!" << endl;
		cout << "You start to wake up by the entrance!" << endl;
		WestDungeon();
	}
  
	if (Cyclops.GetHealth() == 0) {
		cout << endl;
		cout << "Cyclops: What's this? This can't be! I can't move! GRAHH--" << endl;
		cout << "His body begins to melt..." << endl;
		cout << endl;
		cout << "He's done with, let's leave!" << endl;
		westDung = true;
		dungeonsBeaten++;
	}
    
}
