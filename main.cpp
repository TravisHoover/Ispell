/*This program will emulate the Linux command ispell by creating an unordered_map from the 
text file titled dict.txt, then performing operations on a word provided by the user. If the 
word provided is an acceptable word, 'ok' will be displayed. Otherwise various functions will be
run on the word to test for acceptance

Author: Travis Hoover
Class: CSCI 3110
Professor: Dr. Dong
Date: 11/15/2016*/

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include "WordChecker.h"

using namespace std;

int main()
{
	unordered_map<string, int> dictionary;		//declare unordered_map named dictionary
	const int TABLE_SIZE = 88984;
	string entry = "";			//initialize entry to empty string
	string userInput;			//string variable to handle user's input in interface
	int counter = 0;				//counter for while loop to populate map

	fstream myFile;				//create file read variable
	myFile.open("dict.txt");		//open file to read into unordered_map

	while (myFile >> entry)		//while there are entries in list, read list
	{
		dictionary[entry] = counter;
		counter++;
	}

	while (true)
	{
		bool Delete, Insert, Swap, Replace, Space;

		//prompt the user to enter words. 
		cout << "Please input a word: ";
		cin >> userInput;

		//For each word, check whether the word is in the dictionary. 
		if (dictionary[userInput])
		{
			cout << "ok" << endl;		//if the word is in dictionary, print 'ok'
		}

		else
		{
			//If not, it should look for all possible near misses and print them if found
			WordChecker WordChecker(userInput);

			Delete = WordChecker.hashDelete(userInput, dictionary);
			Insert = WordChecker.hashInsert(userInput, dictionary);
			Swap = WordChecker.hashSwap(userInput);
			Replace = WordChecker.hashReplace(userInput, dictionary);
			Space = WordChecker.hashSpace(userInput);

			//If no words are found after WordChecker, print "not found"
			if (Delete || Insert || Swap || Replace || Space)
				true;
			else
				cout << "not found" << endl;

		}
	}
	return 0;
}