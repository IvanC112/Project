#include <iostream>
#include "Header_Files/East_Dungeon.hh"
#include "Header_Files/Global_Variables.hh"
#include "Header_Files/Make_Lowercase.hh"
#include "Header_Files/Validate_Maze.hh"
#include "Header_Files/Validate_RPS.hh"
#include "Classes/Bosses.hh"
#include <limits>
using namespace std;

void EastDungeon() {

	cout << endl;
	cout << "Alright we've made it to the mountains. It smells strange here... Almost like blood!" << endl;
	cout << "Lets follow the scent, it could lead us to the monster.\n\nLook!" << endl;
  cout << "There's a cellar here! Let's check it out, there could be some hints towards the monsters' whereabouts." << endl;
	cout << endl;

  string door1;
  string door2;

  while (door1 != "one" && door2 != "two") {
	cout << "Whoah this room has two doors! Which door should we take?" << endl;
  cout << "Type 'one' for the left door or 'two' for the right door." << endl;
	getline(cin, door1);
	door1 = ValidateMaze(door1);

		// maze one two
		if (door1 == "one") {
			cout << "Seems like you made it to another room with two doors, do we go left or right?\nType 'one' or 'two'." << endl;
			getline(cin, door2);
			door2 = ValidateMaze(door2);
			if (door2 == "two") {
				break;
			}
			else if (door2 == "one") {
				cout << "You seem to be back at the starting point!" << endl;
				door1 = "";
				door2 = "";
				continue;
			}
		}	
		
		if (door1 == "two") {
			cout << "Seems like you made it to another room with two doors, do we go left or right?\nType 'one' or 'two'." << endl;
			getline(cin, door2);
			door2 = ValidateMaze(door2);
			cout << "You seem to be back at the starting point!" << endl;
			door1 = "";
			door2 = "";
			continue;
		}
  }

	cout << "\nLook at that! It's hanging upside down!" << endl;
	cout << "It's a vampire!\n" << endl;

	//Creates a vampire boss
	Boss Vampire; 
	Vampire.SetName("Vampire");
	Vampire.SetDialogue("Vampire: My my, I haven't had a visitor in a long time. Usually I'm the one on the hunt, but this will do. Now then, why don't you entertain me in rock paper scissors!");
  Vampire.SetHealth(3);

	cout << "            .-:::::::::::::-. " << endl;
	cout << "         .:::''':::::::''':::." << endl;
	cout << "        .:::'     `:::'     `:::. " << endl;
	cout << "   .'\\  ::'   ^^^  `:'  ^^^   '::  /`." << endl;
	cout << " :   \\ ::   _.__       __._   :: /   ;" << endl;
	cout << " :     \\`: .' ___\\     /___ `. :'/     ; " << endl;
	cout << ":       /\\   (_|_)\\   /(_|_)   /\\       ;" << endl;
	cout << ":      / .\\   __.' ) ( `.__   /. \\      ;" << endl;
	cout << ":      \\ (        {   }        ) /      ; " << endl;
	cout << ":      `-(     .  ^^  .     )-'      " << endl;
	cout << "  `.       \\  .'<`-._.-'>'.  /       .'" << endl;
	cout << "    `.      \\    \\;`.';/    /      .'" << endl;
	cout << "      `._    `-._       _.-'    _.'" << endl;
	cout << "       .'`-.__ .'`-._.-'`. __.-'`." << endl;
	cout << "     .'       `.         .'       `." << endl;
	cout << "   .'           `-.   .-'           `. " << endl;

  Vampire.PrintDialogue();
  
	cout << "\nAlright, let's get him!\n" << endl;

  srand(time(0));

  string userInputString;
	int userHealth = 4;
	int vampInput;
	int userInput;

	// 0 = ROCK
	// 1 = PAPER
	// 2 = SCISSORS

  while (userHealth > 0 && Vampire.GetHealth() > 0) {
		//set up game
    vampInput = rand() % 3;
    cout << "What will you pick? Type either 'rock', 'paper', or 'scissors'." << endl;
		cin >> userInputString;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		userInput = ValidateRPS(userInputString);

		//results
    if (userInput == vampInput) {
      cout << "Vampire: A tie! How interesting." << endl;
    }
    else if ( (vampInput == 0 && userInput == 2) || (vampInput == 1 && userInput == 0) || (vampInput == 2 && userInput == 1) ) {
				
			if (vampInput == 0) {
				cout << "Vampire: I choose rock!" << endl;
			}
			else if (vampInput == 1) {
				cout << "Vampire: I choose paper!" << endl;
      }
			else if (vampInput == 2) {
				cout << "Vampire: I choose scissors!" << endl;
			}
				
		cout << "Vampire: AHAHHA I won! We're not done here yet, let's keep going!" << endl;
    userHealth--;
  	}
				
    else {
      cout << "Vampire: You won? Impossible! Let me try again!" << endl;
      Vampire.LowerHealth();
    }
	
	}
	
	//If the user runs out of health, retry the dungeon
	if (userHealth == 0) {
		cout << endl;
    cout << "You begin to lose your strength. You blacked out!" << endl;
		cout << "You start to wake up by the entrance!" << endl;
		EastDungeon();
	}

	//If the boss runs out of health, finish dungeon
	if (Vampire.GetHealth() == 0) {
		cout << "Vampire: Huhh! What's this? I can't continue... I've been beaten in my own game? AHRGH-" << endl;
		cout << endl;
		cout << "His body begins to burst into flames..." << endl;
		cout << "We got him! Looks like our job is done, we should get out of here!" << endl;
		eastDung = true;
		dungeonsBeaten++;
	}
	
}