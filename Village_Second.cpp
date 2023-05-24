#include <iostream>
#include "Header_Files/Village_Second.hh"
#include "Header_Files/Global_Variables.hh"
using namespace std;

int randInt(int min, int max) {		//First hand for blackjack
    static bool first = true;
    if (first) {
        srand(time(0)); 
        first = false;
    }
    return min + rand() % (max - min + 1);
}

int getCardValue(int card) {		//Return Card's value for blackjack
    if (card == 1) {
        return 1;
    } else if (card >= 11 && card <= 13) {
        return 10;
    } else {
        return card;
    }
}

void VillageSecond() {

	cout << "What's this?? The forest is on fire! We should hurry up" << endl;
	cout << endl;
	cout << "The village is on the brink of destruction! Where is everyone?!" << endl;
	cout << endl;
	cout << "Village Chief: " << playerName << "! Over here!" << endl;
	cout << "Village Chief: You've made it back, well done. I'm afraid we've been attacked in your absence. A powerful dragon flew in earlier destroying everything. Everyone's been evacuated to safety, but our foe is still loose. It's laid rest by the village docks." << endl;
	cout << "Village Chief: Sorry " << playerName << ", but you're the only one who stands a chance. So please save us!" << endl;

	string headBack;
	cout << endl;
	cout << "Let's head over immediately!"  << endl;
	cout << "Are you ready for this?" << endl;
	cout << "Type 'yes' or 'no'" << endl;
	getline(cin, headBack);

	//User must headback
	while (headBack != "yes") {
		if (headBack == "no") {
			cout << "The village needs us! Should we head back?" << endl;
		}
		else {
			cout << "That is not a valid input. Type either 'yes' or 'no'" << endl;
		}
		getline(cin, headBack);
	}
	
	cout << "\nThere it is!\n" << endl;

	cout << "            \\||/" << endl;
  cout << "              |  @___oo" << endl;
	cout << "    /\\  /\\   / (__,,,,|" << endl;
  cout << "   ) /^\\) ^\\/ _)" << endl;
  cout << "   )   /^\\/   _)" << endl;
  cout << "   )   _ /  / _)" << endl;
  cout << "/\\  )/\\/ ||  | )_)" << endl;
	cout << "<  >      |(,,) )__)" << endl;
 	cout << "||      /    \\)___)\\" << endl;
 	cout << "| \\____(      )___) )___" << endl;
  cout << "\\______(_______;;; __;;;\n" << endl;

	int userTotal = 0;
  int dragonTotal = 0;
	bool userWon = false;

	cout << "Dragon: GROAAAHHA AHAHAHA" << endl;
	cout << "You there! There's nothing left of this village AHAHAHA. Why don't you amuse me in its place with some blackjack!" << endl;

	cout << "\nTime to finish this\n" << endl;
	
    // Deal two cards to the user
    int userCard1 = randInt(1, 13);
    int userCard2 = randInt(1, 13);
    userTotal = getCardValue(userCard1) + getCardValue(userCard2);
    cout << "You were dealt a " << userCard1 << " and a " << userCard2 << "." << endl;

    // Deal two cards to the dragon
    int dragonCard1 = randInt(1, 13);
    int dragonCard2 = randInt(1, 13);
    dragonTotal = getCardValue(dragonCard1) + getCardValue(dragonCard2);
    cout << "Dragon: I was dealt a " << dragonCard1 << " and a hidden card." << endl;

    // User's turn
    while (userTotal < 21) {
        cout << "Your total is " << userTotal << ". Do you want to hit or stand?\n(If you'd like to hit type 'h', otherwise type anything.)" << endl;
        char userChoice;
        cin >> userChoice;
        if (userChoice == 'h') {
            int newCard = randInt(1, 13);
            userTotal += getCardValue(newCard);
            cout << "You were dealt a " << newCard << ". Your total is now " << userTotal << "." << endl;
        } 
        else {
            break;
        }
    }
    // Dragon's turn
    cout << "The dragon reveals the hidden card: " << dragonCard2 << ". Dragon's total is " << dragonTotal << "." << endl;
    while (dragonTotal < 17) {
        int newCard = randInt(1, 13);
        dragonTotal += getCardValue(newCard);
        cout << "Dragon hits and gets a " << newCard << ". Dragon's total is now " << dragonTotal << "." << endl;
    }

    // Determine the winner
    if (userTotal > 21) {
        cout << "You bust. Dragon wins." << endl;
				cout << "\n\nYou begin to lose your strength. You blacked out!" << endl;
			VillageSecond();
    } 
    else if (dragonTotal > 21 && dragonTotal <= 23) {
        cout << "Dragon busts. You win!" << endl;
				cout << "Dragon: AHAHHA that won't be enough. Try and beat me head on!." << endl;
				cout << "'Hint: You must win without the dragon going over 23.'" << endl;
				cout << "We have to beat him, the village is counting on us!\n\n\nYou begin to lose your strength. You blacked out!" << endl;
				VillageSecond();
    } 
    else if (dragonTotal > 23) {
			cout << "Dragon busts. You win!" << endl;
			userWon = true;
		}
		else if (userTotal > dragonTotal) {
        cout << "You win!" << endl;
				userWon = true;
    } 
		else if (dragonTotal > userTotal) {
        cout << "Dragon wins." << endl;
				cout << "\n\nYou begin to lose your strength. You blacked out!" << endl;
				cout << "You start to wake up outside the forest!" << endl;
			VillageSecond();
    } 
		else {
        cout << "It's a tie!" << endl;
				cout << "We have to beat him, the village is counting on us!\n\n\n" << "You begin to lose your strength. You blacked out!" << endl;
				cout << "You start to wake up outside the forest!" << endl;
			VillageSecond();
    }

	if (userWon == true) {
		cout << "\nDragon: Impressive...\nDragon: I never thought I'd be defeated... especially by a human...\nDragon: That was fun I'll give you that-" << endl;
		cout << "\nThe dragon's body starts turning to ash." << endl;
	}
}
