/*
Corner Grocer by Gaelyn Jackson
2-20-2026
The purpose of this project is to let users see the number of items in a grocery list and organize them in a histogram based on what option they select
*/

#include "GroceryTracker.h" //adds header file
#include <iostream>
#include <fstream> //lets the program handle files
#include <cctype> //this makes the program not case sensitive

using namespace std;

//this will initialize the file name and will load all the data
GroceryTracker::GroceryTracker(string fileName) {
	inputFileName = fileName; //assigns a name to input file
	loadDataFromFile(); //reads data from the file and builds the map
	createBackupFile(); //creates the backup file
}


//this will convert lowercase letters to uppercase if the user types in lowercase
string GroceryTracker::toLowerCase(const string& input) {
	string result = input;

	for (char& c : result) { //this will loop through each character until it reaches the end and changes it to lowercase
		c = tolower(c);
	}

	return result;
}

//reads the data from the file and will build a map of the frequency
void GroceryTracker::loadDataFromFile() {
	ifstream inputFile(inputFileName); //this will open the input file
	string currentItem; //this will store the items read from the file

	//gives error if the file isn't able to be opened
	if (!inputFile) {
		cout << "Error\n";
		return;
	}

	while (inputFile >> currentItem) {
		currentItem = toLowerCase(currentItem);
		groceryFrequencyMap[currentItem]++; 
	}

	inputFile.close();
} 


//this creates the frequency.dat file
void GroceryTracker::createBackupFile() {
	ofstream outputFile("frequency.dat"); //names the output file frequency.dat

	for (const auto& pair : groceryFrequencyMap) { //loops through the map
		outputFile << pair.first << " " << pair.second << endl; //shows the items and the number of them
	}

	outputFile.close();
}

//menu option 1
void GroceryTracker::showItemFrequency() {
	string searchItem;

	cout << "Enter an item: ";
	cin >> searchItem;

	searchItem = toLowerCase(searchItem);

	if (groceryFrequencyMap.count(searchItem)) {
		cout << searchItem << ": " << groceryFrequencyMap[searchItem] << endl; //will show the output as x:y (for example, onions: 3)
	}
	else {
		cout << searchItem << " not found.\n";
	}
}

//menu option 2
void GroceryTracker::showAllItemFrequencies() {
	for (const auto& pair : groceryFrequencyMap) {
		cout << pair.first << " " << pair.second << endl;
	}
}

//menu option 3
void GroceryTracker::showHistogram() {
	for (const auto& pair : groceryFrequencyMap) {
		cout << pair.first << " ";

		for (int i = 0; i < pair.second; i++) {
			cout << "*"; 
		}

		cout << endl;
	}
}