#include "LearningStringCompressor.h"
#include<string>
#include<iostream>


LearningStringCompressor::LearningStringCompressor()
{
}


LearningStringCompressor::~LearningStringCompressor()
{
}

const std::string LearningStringCompressor::virtualTalk() {
	return "\nLearningStringCompressor: I implement the virtual function.\n";
}

const std::string LearningStringCompressor::overrideTalk() {
	return "\nLearningStringCompressor: I override the NON-virtual function.\n";
}

void LearningStringCompressor::compress(const std::string& toCompress) {
	//ex: aaabbccdeffffghh -> a3b2c2def4gh2

	//if empty string, cannot compress
	if (toCompress.length() < 1) {
		std::cout << "string to compress was empty";
		return;
	}

	//initialize the character type to the first character of the string
	char charType = toCompress[0];
	int charCount = 1;

	for (int i = 1; i < toCompress.length(); i++) {

		//if the next char is equal to the current char, increment the count
		if (charType == toCompress[i]) {
			charCount++;
		}
		else {
			printCharAndCount(charType, charCount);

			//clear the count and reset the charType
			charType = toCompress[i];
			charCount = 1;
		}
	}

	//the loop is over, so print the last character and its count
	printCharAndCount(charType, charCount);
}

void LearningStringCompressor::printCharAndCount(char charType, int charCount) {
	//print the character
	std::cout << charType;

	//if the char appears more than once, print the number of times it appears
	if (charCount > 1) {
		std::cout << charCount;
	}
}

