#include <iostream>
#include "Header_Files/Dungeons_Beaten.hh"
#include "Header_Files/Global_Variables.hh"

void DungeonsBeaten() {
	cout << "\nSo far you have slain " << dungeonsBeaten << " of the monsters!" << endl;
	
	if (northDung == true) {
		cout << "The Minotaur" << endl;
	}
	
	if (eastDung == true) {
		cout << "The Vampire" << endl;
	}
	
	if (westDung == true) {
		cout << "The Cyclops" << endl;
	}
	
}