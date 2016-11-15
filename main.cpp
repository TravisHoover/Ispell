#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include "WordChecker.h"

using namespace std;

const int TABLE_SIZE = 88984;

class HashEntry {
private:
	int key;
	int value;
public:
	HashEntry(int key, int value) {
		this->key = key;
		this->value = value;
	}

	int getKey() {
		return key;
	}

	int getValue() {
		return value;
	}
};

class HashMap {
private:
	HashEntry **table;
public:
	HashMap() {
		table = new HashEntry*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = NULL;
	}

	int get(int key) {
		int hash = (key % TABLE_SIZE);
		while (table[hash] != NULL && table[hash]->getKey() != key)
			hash = (hash + 1) % TABLE_SIZE;
		if (table[hash] == NULL)
			return -1;
		else
			return table[hash]->getValue();
	}

	void put(int key, int value) {
		int hash = (key % TABLE_SIZE);
		while (table[hash] != NULL && table[hash]->getKey() != key)
			hash = (hash + 1) % TABLE_SIZE;
		if (table[hash] != NULL)
			delete table[hash];
		table[hash] = new HashEntry(key, value);
	}

	~HashMap() {
		for (int i = 0; i < TABLE_SIZE; i++)
			if (table[i] != NULL)
				delete table[i];
		delete[] table;
	}
};

int main()
{
	fstream myFile;
	myFile.open("dict.txt");
	string userInput;

	unordered_map<string, int> dictionary;
	string entry = "";
	int counter = 0;

	while (myFile >> entry)
	{
		dictionary[entry] = counter;
		counter++;
	}

	//prompt the user to enter words. 
	cout << "Please input a word: ";
	cin >> userInput;

	//For each word, check whether the word is in the dictionary. 
	if (dictionary[userInput])
		cout << "ok" << endl;		//if the word is in dictionary, print 'ok'

	//If not, it should look for all possible near misses. 

	//If the program finds any near misses in the dictionary, it should print them. 

	//If not, it should say "not found". 
	else
		cout << "not found" << endl;
	return 0;
}