using namespace std;
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include "LearningBase.h"
#include "Interview.h"
#include "BinaryTree.h"

std::vector<std::vector<int>> findRepeatedComponents(const std::string& input) {
	//"redblredblredred" -> "ababaa"
	queue<vector<int>> skipPairs = queue<vector<int>>();
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
}

/*
void ptrtest() {
	LearningBase* lb1 = new LearningBase();
	const LearningBase& lb2 = *lb1;

	std::cout << "\n\first nptr is: " << lb1 << " and ref says: " << lb2.overrideTalk() << "with id " << lb2.getId();

	delete lb1;

	//this could cause NPE because the object has been cleared out of memory and the id has been reset
	std::cout << "\n\then nptr is: " << lb1 << " and ref says: " << lb2.overrideTalk() << " with id " << lb2.getId();
}*/

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

int main(int argc, const char * argv[]) {

//	bitshift();

//	std::cout << "Original: aaaabbcccdefffg" << std::endl;
//	std::cout << "Expected: a4b2c3def3g" << std::endl;
//	std::cout << "Compressed: ";

//	LearningStringCompressor::compress("aaaabbcccdefffg");

//	findRepeatedComponents("abba");

//	const char* numberWords[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

//	LearningBase::ptrArithmeticDemo();
//	cout << LearningBase::avgDistanceAB("abccaacabcab") << endl;
//	vector<string> strVector = {
//		"abc", "test", "vac", "bac", "london", "cba", "cav", "lon", "pst"
//	};
//	LearningBase base = LearningBase();
//	base.anagramSort(strVector);
//	cout << LearningBase::sayWhatYouSee("aadjdfddkdedmfffffvirewo");

//	Interview::sortMapByKey();

	/*
	BinaryTree* tree = new BinaryTree(10);
	tree->insert(2);
	tree->insert(20);

	cout << endl << "depth: " << tree->getDepth() << endl;

	tree->insert(6);
	tree->insert(98);
	tree->insert(10493);
	BinaryTree::inorder(tree);

	cout << endl << "depth: " << tree->getDepth() << endl;

	//to STORE the depth, create a new "tree metadata" class to hold a BinaryTree,
	//and store the depth as an instance variable of that class. depth would need to be 
	//accessible from within each tree node, so pass the reference
	//into the addNode function instead of holding a reference on each node instance - this saves memory.

	
	BinaryTree::balance(tree);
	BinaryTree::inorder(tree);
	cout << endl << "depth: " << BinaryTree::calculateDepth(tree);
	
	
	
	delete tree;*/

//	AlgorithmPractice::shuntingYard("hello bob");
	
	//add "find smallest integer of rotated sorted array" here.
	vector<int> a0 = {2, 3, 4, 5, 6, 7, 8, 9, 1};
	vector<int> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> a2 = {9, 1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> a3 = {8, 9, 1, 2, 3, 4, 5, 6, 7};
	vector<int> a4 = {7, 8, 9, 1, 2, 3, 4, 5, 6};
	vector<int> a5 = {6, 7, 8, 9, 1, 2, 3, 4, 5};
	vector<int> a6 = {5, 6, 7, 8, 9, 1, 2, 3, 4};
	vector<int> a7 = {4, 5, 6, 7, 8, 95, 1, 2, 3};
	vector<int> a8 = {2, 2, 2, 6, 7, 8, 9, 1, 2};
	vector<int> a9 = {2, 3, 4, 5, 6, 7, 8, 9, 1};
	vector<int> a10 = {7, 7, 7, 7, 7, 7, 7, 7};
	vector<int> a11 = {1, 7, 7, 7, 7, 7, 7, 7, 7};
	vector<int> a12 = {2, 7, 7, 7, 7, 7, 7, 7, 7, 1};

	vector<int> aa = {1};
	vector<int> ab = {2, 3};
	vector<int> ac = {3, 2};
	vector<int> ad = {10, 11, 4, 5, 5, 5, 5, 6, 7, 8, 9, 9};


	cout << "a0: " << Interview::smallestInRotatedSortedArray(a0) << ", should be 1 " << endl;
	cout << "a1: " << Interview::smallestInRotatedSortedArray(a1) << ", should be 1 " << endl;
	cout << "a2: " << Interview::smallestInRotatedSortedArray(a2) << ", should be 1 " << endl;
	cout << "a3: " << Interview::smallestInRotatedSortedArray(a3) << ", should be 1 " << endl;
	cout << "a4: " << Interview::smallestInRotatedSortedArray(a4) << ", should be 1 " << endl;
	cout << "a5: " << Interview::smallestInRotatedSortedArray(a5) << ", should be 1 " << endl;
	cout << "a6: " << Interview::smallestInRotatedSortedArray(a6) << ", should be 1 " << endl;
	cout << "a7: " << Interview::smallestInRotatedSortedArray(a7) << ", should be 1 " << endl;
	cout << "a8: " << Interview::smallestInRotatedSortedArray(a8) << ", should be 1 " << endl;
	cout << "a9: " << Interview::smallestInRotatedSortedArray(a9) << ", should be 1 " << endl;
	cout << "a10: " << Interview::smallestInRotatedSortedArray(a10) << ", should be 7 " << endl;
	cout << "a11: " << Interview::smallestInRotatedSortedArray(a11) << ", should be 1 " << endl;
	cout << "a12: " << Interview::smallestInRotatedSortedArray(a12) << ", should be 1 " << endl;
	cout << "aa: " << Interview::smallestInRotatedSortedArray(aa) << ", should be 1 " << endl;
	cout << "ab: " << Interview::smallestInRotatedSortedArray(ab) << ", should be 2 " << endl;
	cout << "ac: " << Interview::smallestInRotatedSortedArray(ac) << ", should be 2 " << endl;
	cout << "ad: " << Interview::smallestInRotatedSortedArray(ad) << ", should be 4 " << endl;
//	while (1);
	return 0;
}
