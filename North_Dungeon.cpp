#include <iostream>
#include <limits>
#include "Header_Files/North_Dungeon.hh"
#include "Header_Files/Make_Lowercase.hh"
#include "Classes/Bosses.hh"
#include "Header_Files/Global_Variables.hh"
#include "Header_Files/Validate_Maze.hh"
using namespace std;

void NorthDungeon() {
	
	cout << endl; 
  cout << "Alright we've made it to the waterfall. It looks like there are some footprints heading downstream." << endl;
	cout << endl;
	cout << "Look!" << endl;
  cout << "There's a cave here! Let's check it out, the monster could be hiding in there." << endl;
	cout << endl;

  string direction1;
  string direction2;

		//Creates a maze with correct paths TWO TWO
	 while (direction1 != "two" && direction2 != "two") {
		cout << "Seems as if there's a fork in the road. Which path should we take?" << endl;
		cout << "Type 'one' for left or 'two' for right." << endl;
	getline(cin, direction1);
	direction1 = ValidateMaze(direction1);

		if (direction1 == "two") {
			cout << "Seems like you made it to another fork in the road, do we go left or right?\nType 'one' or 'two'." << endl;
			getline(cin, direction2);
			direction2 = ValidateMaze(direction2);
			if (direction2 == "two") {
				break;
			}
			else if (direction2 == "one") {
				cout << "You seem to be back at the starting point!" << endl;
				direction1 = "";
  			direction2 = "";
				continue;
			}
		}	
		 
		if (direction1 == "one") {
			cout << "Seems like you made it to another fork in the road, do we go left or right?\nType 'one' or 'two'." << endl;
			getline(cin, direction2);
			direction2 = ValidateMaze(direction2);
			cout << "You seem to be back at the starting point!" << endl;
			direction1 = "";
  		direction2 = "";
			continue;
		}
  }

	cout << "\n\nLook there it is! It's a Minotaur!\n" << endl;

	Boss Minotaur;  
	Minotaur.SetName("Minotaur");
	Minotaur.SetHealth(5);
	Minotaur.SetDialogue("The beast lets out a savage roar!!! \nMinotaur: I won't accept defeat till you can outsmart me!\n");

	cout << "     |\\____/|" << endl;
	cout << "    (\\|----|/)" << endl;
	cout << "     \\ 0  0 /" << endl;
	cout << "      |    |" << endl;
	cout << "   ___/\\../\\____" << endl;
	cout << "  /     --       \\" << endl;
	cout << " /  \\         /   \\" << endl;
	cout << "|    \\___/___/(   |" << endl;
	cout << "\\   /|  }{   | \\  )" << endl;
	cout << " \\  ||__}{__|  |  |" << endl;
	cout << "  \\  |;;;;;;;\\  \\ / \\_______" << endl;
	cout << "  \\ /;;;;;;;;| [,,[|======'" << endl;
	cout << "     |;;;;;;/ |     /" << endl;
	cout << "     ||;;|\\   |" << endl;
	cout << "     ||;;/|   /" << endl;
	cout << "     \\_|:||__|" << endl;
	cout << "      \\ ;||  /" << endl;
	cout << "      |= || =|" << endl;
	cout << "      |= /\\ =|" << endl;
	cout << "     /_/  \\_\\" << endl;

	cout << "\nHere we go, let's get him!" << endl;

  srand(time(0));

	int userGuess;
	int userHealth = 4;
	int randNum1;
	int randNum2;

	Minotaur.PrintDialogue();
	while (userHealth > 0 && Minotaur.GetHealth() > 0) {
		//Creates game asking the product of two random numbers
		randNum1 = rand() % 20;
		randNum2 = (rand() % 15) + 1;
		cout << "Minotaur: What is the product of " << randNum1 << " and " << randNum2 << "?" << endl;
    cin >> userGuess;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		while (cin.fail()) { //clears input buffer and reinputs userGuess
				cout << "That is not a valid input. Try again." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> userGuess;
		}
		
    if (userGuess != randNum1 * randNum2) {
      cout << "Minotaur: HAHAHAHAHA! Wrong its " << randNum1 * randNum2 << " you fool!" << endl;
			userHealth--;
			continue;
    }
		else {
			Minotaur.LowerHealth();
			cout << "Minotaur: ARGHH. Lucky Guess! This won't happen again!" << endl;
		}
		
		if (Minotaur.GetHealth() == 0) {
      break;
    }
	}

	//If user runs out of health, retry dungeon
	if (userHealth == 0) {
		cout << "\n\nYou begin to lose your strength. You blacked out!" << endl;
		cout << "You start to wake up by the entrance!" << endl;
		NorthDungeon();
	}

	//If Minotaur runs out of health, end dungeon
	if (Minotaur.GetHealth() == 0) {
		cout << endl;
		cout << "Minotaur: HUH? I can't move! Unbelievable... I've been bested... by the lik--" << endl;
		cout << endl;
		cout << "The Minotaur begins to disintegrate." << endl;
		cout << "We did it! Now let's get out of here quick!." << endl;
		dungeonsBeaten++;
		northDung = true;
	}
	
}