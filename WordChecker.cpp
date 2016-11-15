#include "WordChecker.h"
#include <iostream>
#include <string>

using namespace std;

WordChecker::WordChecker(std::string entry)
{
	string m_entry = entry;
}

/*Construct every string that can be made by deleting one letter from the word. (n possibilities, where n is the length of the word)*/
bool WordChecker::hashDelete(std::string entry)
{
	//for loop to delete letter and check against dictionary
	for (int i = 0; i < entry.length(); i++)
	{
		//store temp letter in word
		char temp = entry.at(i);

		//make new word with entry - [i]
		entry.erase(i, 1);

		//check if altered word is an acceptable word
		

		//put i back after checking
		entry.insert(i, 1, temp);
	}
	return false;
}

/*Construct every string that can be made by inserting any letter of the alphabet at any position in the string. (26*(n+1) possibilities)*/
bool WordChecker::hashInsert(std::string entry)
{
	for (int i = 0; i < entry.length(); i++) //for loop to cycle through each position of string
	{
		for (int j = 97; j < 123; j++)		//for loop to insert each letter of alphabet. I will loop through the ASCII values for lower case alphabet
		{
			
		}
	}
	return false;
}

/*Construct every string that can be made by swapping two neighboring characters in the string. (n-1 possibilities)*/
bool WordChecker::hashSwap(std::string entry)
{
	string temp = entry;
	for (int i = 0; i < entry.length(); i++)
	{
		for (int j = 0; j < entry.length(); j++)
		{
			swap(entry[i], entry[j]);

			//check if newly created word is an acceptable one in the dictionary
		}
	}
	return false;
}

/*Construct every string that can be made by replacing each letter in the word with some letter of the alphabet. (26*n possibilities (including the original word n times, which is probably easier than avoiding it))*/
bool WordChecker::hashReplace(std::string entry)
{
	for (int i = 0; i < entry.length(); i++) //for loop to cycle through each position of string
	{
		for (int j = 97; j < 123; j++)		//for loop to insert each letter of alphabet. I will loop through the ASCII values for lower case alphabet
		{

		}
	}
	return false;
}

/*Construct every pair of strings that can be made by inserting a space into the word. (n-1 pairs of words; you have to check separately in the dictionary for each word in the pair)*/
bool WordChecker::hashSpace(std::string entry)
{
	for (int i = 0; i < entry.length(); i++)
	{

	}
	return false;
}

WordChecker::~WordChecker()
{
}
