#include <iostream>
#include "Header_Files/Village.hh"
#include "Header_Files/Global_Variables.hh"
#include "Header_Files/Make_Lowercase.hh"
#include "Classes/NPCS.hh"
#include "Header_Files/Validate.NPCInput.hh"
#include <limits>
using namespace std;

void Village() {
	//creates 3 NPCS for the player to talk to
	NPC Blacksmith;
	Blacksmith.SetRole("Blacksmith");
	Blacksmith.SetDialogue("Blacksmith: If you're truly going, you should know that none have succeeded. I've forged armor and weapons for dozens, only for them to never return home. Be careful out there.");

	NPC Butcher;
	Butcher.SetRole("Butcher");
	Butcher.SetDialogue("Butcher: I've overheard some people talking about some strange horned beast out by the waterfall to the north. I'd stay away from there if I were you.");

	NPC Guard;
	Guard.SetRole("Guard");
	Guard.SetDialogue("Guard: Hey, I've heard about you. You should be careful out there, me and a few others were near the mountains on the east till we saw some hooded figure. I was able to make out its pale skin and sharp fangs. It was almost unhuman.");

	cout << endl;
	cout << "Village Chief: We have been awaiting your arrival " << playerName << ". I'm sure you are aware of the looming danger, now will you help us?" << endl;
	cout << "Type 'yes' or 'no'" << endl;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string helpChoice;
	getline(cin, helpChoice);
	
	//User must help out
	//Serves as a joke
	
	while (helpChoice != "yes") {
		cout << "Sorry, I didn't quite catch that. Will you be helping us?" << endl;
		getline(cin, helpChoice);
	}

	cout << endl;
	cout << "Village Chief: Perfect, I knew we could count on you! Now, before you depart, you should know that our resource gatherers have spotted what looks to be a one-eyed creature in the caves to the west. Unfortunately, that is all I know, the rest is on your shoulders young one. Feel free to make preparations and rest before your long journey." << endl;
	cout << endl;
	
	cout << "Before we head out, we should speak to some of the villagers. They might have some clues about what lies ahead." << endl;

	string npcChoice;

	cout << endl;
	cout << "Who would you like to talk to?" << endl;
	cout << "The Blacksmith, Butcher, or Guard?" << endl;
	cout << "Type either 'one' for the Blacksmith, 'two' for the Butcher, 'three' for the Guard, or 'no' for none." << endl;
	
	getline(cin, npcChoice);

	npcChoice = ValidateNPCInput(npcChoice);

	while (npcChoice == "one" || npcChoice == "two" || npcChoice == "three") {
		
		if (npcChoice == "no") {
      break;
    }
		else if (npcChoice == "one") {
			Blacksmith.GetDialogue();
		}
		else if (npcChoice == "two") {
      Butcher.GetDialogue();
    }	
		else if (npcChoice == "three") {
      Guard.GetDialogue();
    }
		
		cout << endl;
		cout << "Would you like to talk to anyone again?" << endl;
		cout << "Type either 'one' for the Blacksmith, 'two' for the Butcher, 'three' for the Guard, or 'no' for none." << endl;
		getline(cin, npcChoice);
		npcChoice = ValidateNPCInput(npcChoice);
	}
	
	cout << endl;
	cout << "It's about time we head out then, let's get going." << endl;	

}