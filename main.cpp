#include <iostream>
#include "Header_Files/Instructions.hh"
#include "Header_Files/Village.hh"
#include "Header_Files/Global_Variables.hh"
#include "Header_Files/East_Dungeon.hh"
#include "Header_Files/North_Dungeon.hh"
#include "Header_Files/West_Dungeon.hh"
#include "Header_Files/Dungeons_Beaten.hh"
#include "Header_Files/Village_Second.hh"
#include "Header_Files/Make_Lowercase.hh"
#include "Header_Files/Choose_Direction.hh"
#include <limits>
using namespace std;

int main() {

	cout << "Welcome to the village of Arcadia!\n" << endl;

	Instructions();

	cout << "In our small village in the depths of a forest, people lived peacefully and relied on resources from the forest to survive. However, one day a mysterious cloud covered the skies in pitch darkness. With it came along violent creatures that threatened the people’s safety. These monsters reside in different locations across the forest and will often emerge, interfering with resource gatherers. Many young villagers have risen to fight these monsters, but they were no match for their strength. The forest is being destroyed, and the peace of our village is threatened. Our fate is in your hands, you are the only one who stands a chance. Tell me, what is your name, young one?" << endl;

	cin >> playerName;
  
	//Changes first letter capital, and everything else lowercase.
	
	playerName.at(0) = toupper(playerName.at(0));
	MakeLowercase(playerName.substr(1, playerName.size() - 1));

	cout << endl;
	cout << playerName << "?" << endl;
	cout << "Well " << playerName << ", let us go and speak to the village chief." << endl;

	Village();
	ChooseDirection();
	
	cout << endl;
	cout << "That should be all of them. Let's head back and report to the village chief.\n" << endl;

	VillageSecond();

	cout << endl;
	cout << "Lets notify the village!" << endl;
	cout << endl;

	cout << "Village Chief: " << playerName << " you've done it! You defeated the dragon! We cannot thank you enough. You've dealt with each of our village's threats. Many have tried before you and only you've been successful. You have our utmost gratitude!" << endl;
	cout << endl;

	cout << "Now that the monsters have been dealt with, Arcadia was finally left in peace." << endl;
	cout << "The village's resource gatherers were able to go on expeditions safely and Arcadia thrived." << endl;
	cout << "All thanks to " << playerName << "!" << endl;

	cout << "\n\n\nThe End." << endl;
    
  return 0;
}