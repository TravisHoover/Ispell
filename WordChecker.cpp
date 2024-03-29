/*This is the implementation file for the WordChecker class. It will handle
all cases to test for near misses. It performs various functions on the user's
input and checks to see if the results of those functions are words in the dictionary,
returning them if they are*/

#include "WordChecker.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

WordChecker::WordChecker(std::string)
{
}

/*Construct every string that can be made by deleting one letter from the word. (n possibilities, where n is the length of the word)*/
bool WordChecker::hashDelete(std::string entry, std::unordered_map<std::string, int>& dictionary)
{
	std::vector<std::string> v; //vector to hold new words

	//for loop to delete letter and check against dictionary
	for (int i = 0; i < entry.length(); i++)
	{
		//store temp letter in word
		char temp = entry.at(i);

		//delete letter from word
		entry.erase(i, 1);

		//search dictionary for entry
		std::unordered_map<std::string, int>::const_iterator itr = dictionary.find(entry);
		if (itr != dictionary.end())
		{
			v.push_back(entry);		//add entry to vector
		}

		//put i back after checking
		entry.insert(i, 1, temp);
	}
	
	//create set from vector, by default will only hold unique values(no duplicates)
	std::set<std::string> s(v.begin(), v.end());
	
	//print out set
	for (std::set<std::string>::const_iterator j = s.begin(); j != s.end(); ++j)
		std::cout << *j << std::endl;

	if (s.empty())
		return false;	//if set is empty return false
	else
		return true;
}

/*Construct every string that can be made by inserting any letter of the alphabet at any position in the string. (26*(n+1) possibilities)*/
bool WordChecker::hashInsert(std::string entry, std::unordered_map<std::string, int>& dictionary)
{
	std::vector<std::string> v; // vector to hold found words after inserting letters

	for (int i = 0; i < entry.length(); i++) //for loop to cycle through each position of string
	{
		for (int j = 97; j < 123; j++)		//for loop to insert each letter of alphabet. I will loop through the ASCII values for lower case alphabet
		{
			char temp = entry.at(i);		//store temp letter in word
			char newChar = j;			//new letter to be inserted

			entry.insert(i, 1, newChar);		//make new word with replaced letter
			//check if new word is in the dictionary
			std::unordered_map<std::string, int>::const_iterator itr = dictionary.find(entry);
			if (itr != dictionary.end())
			{
				v.push_back(entry);
			}

			//delete inserted letter
			entry.erase(i, 1);
		}
	}

	//create set from vector, by default will only hold unique values(no duplicates)
	std::set<std::string> s(v.begin(), v.end());

	//print out set
	for (std::set<std::string>::const_iterator j = s.begin(); j != s.end(); ++j)
		std::cout << *j << std::endl;

	if (s.empty())
		return false;	//if set is empty return false
	else
		return true;
}

/*Construct every string that can be made by swapping two neighboring characters in the string. (n-1 possibilities)*/
bool WordChecker::hashSwap(std::string entry, std::unordered_map<std::string, int>& dictionary)
{
	std::vector<std::string> v; // vector to hold found words after swapping

	for (int i = 0; i < entry.length(); i++) //for loop to cycle through each position of string
	{
		for (int j = 0; j < entry.length(); j++)		//second for loop for swapping
		{
			char temp = entry.at(i);			//store first letter to swap
			char temp2 = entry.at(j);		//store second letter to swap
			std::string temp3 = entry;
			entry.at(i) = temp2;				//perform the swap at i
			entry.at(j) = temp;				//perform the swap at j

			std::unordered_map<std::string, int>::const_iterator itr = dictionary.find(entry);	//check if new word is in the dictionary
			if (itr != dictionary.end() && temp3 != entry)
			{
				v.push_back(entry);		//if it is in the dictionary, push back in vector
			}

			//restore entry before continuing loop
			entry.at(i) = temp;
			entry.at(j) = temp2;
		}
	}

	//create set from vector, by default will only hold unique values(no duplicates)
	std::set<std::string> s(v.begin(), v.end());

	//print out set
	for (std::set<std::string>::const_iterator j = s.begin(); j != s.end(); ++j)
		std::cout << *j << std::endl;

	if (s.empty())
		return false;	//if set is empty return false
	else
		return true;
}

/*Construct every string that can be made by replacing each letter in the word with some letter of the alphabet. (26*n possibilities (including the original word n times, which is probably easier than avoiding it))*/
bool WordChecker::hashReplace(std::string entry, std::unordered_map<std::string, int>& dictionary)
{
	std::vector<std::string> r; // vector to hold found words after replacement

	for (int i = 0; i < entry.length(); i++) //for loop to cycle through each position of string
	{
		for (int j = 97; j < 123; j++)		//for loop to insert each letter of alphabet. I will loop through the ASCII values for lower case alphabet
		{
			char temp = entry.at(i);		//store temp letter in word
			std::string temp2 = entry;
			char newChar = j;			//new letter to be inserted (converts j to ASCII char)

			//make new word with replaced letter
			entry.replace(i, 1, 1, newChar);

			//check if new word is in the dictionary
			std::unordered_map<std::string, int>::const_iterator itr = dictionary.find(entry);
			if (!(itr == dictionary.end()) && entry != temp2)
			{
				r.push_back(entry);
			}

			//put i back after checking
			entry.replace(i, 1, 1, temp);
		}
	}

		//create set from vector, by default will only hold unique values(no duplicates)
		std::set<std::string> s(r.begin(), r.end());

		//print out set
		for (std::set<std::string>::const_iterator itr = s.begin(); itr != s.end(); ++itr)
			std::cout << *itr << std::endl;

		if (s.empty())
			return false;	//if set is empty return false
		else
			return true;
}

/*Construct every pair of strings that can be made by inserting a space into the word. (n-1 pairs of words; you have to check separately in the dictionary for each word in the pair)*/
bool WordChecker::hashSpace(std::string entry, std::unordered_map<std::string, int>& dictionary)
{
	std::vector<std::string> v; // vector to hold found words after replacement

	for (int i = 1; i < entry.length(); i++) //for loop to cycle through each position of string
	{
		entry.insert(i, 1, ' ');		//make new words by inserting space

		std::unordered_map<std::string, int>::const_iterator itr = dictionary.find(entry);	//check if new word is in the dictionary

		if (itr != dictionary.end())
		{
			v.push_back(entry);
		}

		//delete inserted letter
		entry.erase(i, 1);
	}

	//create set from vector, by default will only hold unique values(no duplicates)
	std::set<std::string> s(v.begin(), v.end());

	//print out set
	for (std::set<std::string>::const_iterator j = s.begin(); j != s.end(); ++j)
		std::cout << *j << std::endl;

	if (s.empty())
		return false;	//if set is empty return false
	else
		return true;
}
