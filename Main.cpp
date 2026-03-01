/*
Corner Grocer by Gaelyn Jackson
2-20-2026
The purpose of this project is to let users see the number of items in a grocery list and organize them in a histogram based on what option they select
*/

#include <iostream>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

//shows the menu
void displayMenu() {
	cout << "Please select an option from the menu." << endl;
	cout << "\n------MENU------\n";
	cout << "1. Search item frequency\n";
	cout << "2. Print all item frequencies\n";
	cout << "3. Print histogram\n";
	cout << "4. Exit\n";
}

//this will accept the user input
int getUserChoice() {
	int choice;

	while (true) { //loops until the user input is valid
		cin >> choice;

		if(cin.fail()) { //shows error if the user does not type a number
			cout << "Error, please enter a number 1-4"; 
			cin.clear(); //this will let the user type a number again after an error
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (choice < 1 || choice > 4) { //shows an error if the user types either 0 or a number greater than 4
			cout << "Error, please enter a number 1-4";
		}
		else {
			return choice;
		}
	}
}

int main() {
	//this will create the GroceryTracker object 
	GroceryTracker tracker("CS210_Project_Three_Input_File.txt");

	int userChoice; //keeps the users typed choice

	do {
		displayMenu(); //shows the menu
		userChoice = getUserChoice();

		switch (userChoice) {
			case 1:
			tracker.showItemFrequency();
			break;

			case 2: 
			tracker.showAllItemFrequencies();
			break;

			case 3:
			tracker.showHistogram();
			break;

			case 4:
			cout << "Goodbye\n";
			break;
		}

	} while (userChoice != 4); //this will loop until the user types 4

	return 0;
}