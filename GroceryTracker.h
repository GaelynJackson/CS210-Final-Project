/*
Corner Grocer by Gaelyn Jackson
2-20-2026
The purpose of this project is to let users see the number of items in a grocery list and organize them in a histogram based on what option they select
*/

#ifndef GROCERYTRACKER_H 
#define GROCERYTRACKER_H
#include <map>
#include <string>

using namespace std;

//this will define the GroceryTracker class
class GroceryTracker {
	private:
	//this stores the frequency of the items in the list
	map<string, int> groceryFrequencyMap;
	//this will store the file name
	string inputFileName;
	//This will let the user either type in upper or lowercase without an error showing up
	string toLowerCase(const string& input);

	public:
	//constructor for the file that will initialize the objects 
	GroceryTracker(string fileName);
	//this will read from the text file and create a new file
	void loadDataFromFile(); //this will build the map for the frequency
	void createBackupFile(); //this writes the frequency data onto frequency.dat
	//menu options
	void showItemFrequency(); //option 1: search for a specific item 
	void showAllItemFrequencies(); //option 2: shows all items and frequency
	void showHistogram(); //option 3: shows a histogram from data in text file
};

#endif