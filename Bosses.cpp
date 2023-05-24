#include <iostream>
#include "Classes/Bosses.hh"

using namespace std;

void Boss::LowerHealth() {
	health -= 1;
}

void Boss::SetDialogue(string dialogue) {
	this->dialogue = dialogue;
}

void Boss::SetName(string name) {
  this->name = name;
}

void Boss::SetHealth(int health) {
  this->health = health;
}

void Boss::PrintDialogue() {
	cout << "\n" << dialogue << endl;
}

string Boss::GetName() {
  return name;
}

int Boss::GetHealth() {
	return health;
}