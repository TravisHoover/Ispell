#pragma once
#include <string>

class WordChecker
{
public:
	WordChecker();

	//Construct every string that can be made by deleting one letter from the word. (n possibilities, where n is the length of the word)
	std::string hashDelete();

	//Construct every string that can be made by inserting any letter of the alphabet at any position in the string. (26*(n+1) possibilities)
	std::string hashInsert();

	//Construct every string that can be made by swapping two neighboring characters in the string. (n-1 possibilities)
	std::string hashSwap();

	//Construct every string that can be made by replacing each letter in the word with some letter of the alphabet. (26*n possibilities (including the original word n times, which is probably easier than avoiding it))
	std::string hashReplace();

	//Construct every pair of strings that can be made by inserting a space into the word. (n-1 pairs of words; you have to check separately in the dictionary for each word in the pair)
	std::string hashSpace();

	~WordChecker();
};

