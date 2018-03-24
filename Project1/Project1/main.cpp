#include <iostream>
#include "LearningBase.h"
#include "LearningStringCompressor.h"
#include<string>
#include<vector>
#include <queue>

void ptrtest() {
	LearningBase* lb1 = new LearningBase();
	const LearningBase& lb2 = *lb1;

	std::cout << "\n\first nptr is: " << lb1 << " and ref says: " << lb2.overrideTalk() << "with id " << lb2.getId();

	delete lb1;

	//this could cause NPE because the object has been cleared out of memory and the id has been reset
	std::cout << "\n\then nptr is: " << lb1 << " and ref says: " << lb2.overrideTalk() << " with id " << lb2.getId();
}

void bitshift() {
	//one: 0x1 (16^0)

	//sixteen: 0x10 (16^1)
	//fifteen: 0xF = 0x10 - 1

	//256: 0x100 (16^2)
	//255: 0xFF = 0x100 - 1

	//4096: 0x1000 (16^3)
	//4095: 0xFFF = 0x1000 - 1

	//so all hex numbers that are all 'F's will end in 5.

/*	unsigned int sixteen = 0x10;
	unsigned int eight = sixteen >> 1;
	unsigned int thirtytwo = sixteen << 1;
	std::cout << "\nEight: " << eight << "\nSixteen: " << sixteen << "\nThirty-two: " << thirtytwo << std::endl;*/

	//this is:   1*16^1 + 15,        2*16^1 + 15,         3*16^1 + 15...       etc
	std::cout << "0x1F: " << 0x1F << " 0x2F: " << 0x2F << " 0x3F: " << 0x3F << std::endl;
}



std::vector<std::vector<int>> findRepeatedComponents(const std::string& input) {
	//"redblredblredred" -> "ababaa"
	std::queue<std::vector<int>> skipPairs = std::queue<std::vector<int>>();
	std::vector<std::vector<int>> allPtnOccurrences = std::vector<std::vector<int>>();

	//check all patterns from the beginning to end of the string
	for (int ptnStart = 0; ptnStart < input.length(); ptnStart++) {
		std::vector<int> thisPtnOccurrences = std::vector<int>();
		int thisPtnLength = 0;

		//skip over the parts of the string that contain already-recorded patterns
		while (!skipPairs.empty()) {
			std::vector<int> toSkip = skipPairs.front();
			if (ptnStart >= toSkip[0] && ptnStart <= (toSkip[0] + toSkip[1])) {
				ptnStart += (toSkip[0] + toSkip[1] - ptnStart);
				skipPairs.pop();
			}
			else {
				break;
			}
		}

		for (int ptnEnd = ptnStart + 1; ptnEnd < input.length(); ptnEnd++) {

			//the candidate pattern
			std::string ptnToCheck = input.substr(ptnStart, ptnEnd - ptnStart);
			if (ptnToCheck.empty()) {
				break;
			}
			std::vector<int> occurrences = std::vector<int>();

			//record all occurrences of this pattern
			size_t pos = input.find(ptnToCheck, 0);
			while (pos != std::string::npos) {
				occurrences.push_back(pos);
				pos = input.find(ptnToCheck, pos + 1);
			}

			//if more or same number of occurrences were found than last time, replace last with this time
			if (occurrences.size() >= thisPtnOccurrences.size()) {
				thisPtnOccurrences = occurrences;
				thisPtnLength = ptnToCheck.length();
			}
			else {
				//if fewer occurrences were found, record the previous pattern and the string areas to skip
				for (std::vector<int>::iterator it = thisPtnOccurrences.begin(); it != thisPtnOccurrences.end(); ++it) {

					//instead of a vector, this needs to be a min-heap with *it as the comparable
					std::vector<int> skipPair = std::vector<int>();
					skipPair.push_back(*it);
					skipPair.push_back(thisPtnLength);
					skipPairs.push(skipPair);
				}
				break;
			}
		}

		if (!thisPtnOccurrences.empty()) {
			allPtnOccurrences.push_back(thisPtnOccurrences);
		}
	}
	return allPtnOccurrences;

	//Start at the beginning
	//Take the first character and see if it's repeated 
	//Assume tokenize on SMALLEST repeated substring.
	//So in "redblredblredred", 'red' is found as the first pattern but NOT 'redbl'.
	//Do this by breaking the loop and keeping the previous answer as soon as the number of found repetitions decreases.
	//Build a hash table of token->indices, but convert the token to a NUMBER, i.e. 'red'->1, 'bl'->2. Can use a simple array for this and init
	//each array to size input/2 (+1 if input is odd length). That way the output is automatically sorted by occurrence and it's easy to compare to other outputs.
	//At the end of the looping, iterate over the keyset/array indices and return a vector of the discovered subarrays/indices.
	//During the looping, will somehow need to reference the current result to make sure the newly found patterns aren't overlapping with the old patterns.
	//Could do this by passing the loop indices into the loop as a range, and updating those ranges continually as the tokenization progresses.
	//So it would start by looping over one range of 0->input.length(), but after finding 'red' it is then looping over two ranges of
	//3,4 and 8,9
}

int main() {
	std::cout << "Hello world!\n";
//	bitshift();

	std::cout << "Original: aaaabbcccdefffg" << std::endl;
	std::cout << "Expected: a4b2c3def3g" << std::endl;
	std::cout << "Compressed: ";

	LearningStringCompressor::compress("aaaabbcccdefffg");

	findRepeatedComponents("abba");

	//	std::string mystring = "a man a plan a canal panama";
/*	LearningBase::isPalindrome(mystring);

	mystring = "mystring";
	LearningBase::isPalindrome(mystring);*/

	//these didn't work
	//	LearningBase mBase = LearningBase();
//	LearningBase mCompressor = LearningStringCompressor();

//	LearningBase* mBase = new LearningBase();
//	LearningBase* mCompressor = new LearningStringCompressor();

//	const std::string& output3 = mBase.comp3();
//	std::cout << output3;
//	const std::string& output2 = "my string test";
//	std::cout << output2;
//	std::string output = mBase.comp2();
//	std::cout << output;

	//expect the response from LearningBase
//	std::cout << mBase->virtualTalk();

	//expect the response from LearningBase
//	std::cout << mBase->overrideTalk();

	//expect the response from LearningStringCompressor
//	std::cout << mCompressor->virtualTalk();

	//expect the response from LearningBase
//	std::cout << mCompressor->overrideTalk();

//	ptrtest();

	while (1);
	return 0;
}