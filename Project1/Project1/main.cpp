
using namespace std;
#include <iostream>
#include <sstream>
#include <vector>
//#include "LearningBase.h"
//#include "Interview.h"
#include "BinaryTree.h"

int main(int argc, const char * argv[]) {

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

	BinaryTree* tree = new BinaryTree(10);
	tree->addNode(2);
	tree->addNode(20);
	tree->addNode(6);
	tree->addNode(98);
	tree->addNode(10493);
//	string treeAsString = "";
	BinaryTree::inorder(tree);
//	std::cout << treeAsString;
//	cout << tree->getData();

	//to STORE the depth, create a new "tree metadata" class to hold a BinaryTree,
	//and store the depth as an instance variable of that class. depth would need to be 
	//accessible from within each tree node, so pass the reference
	//into the addNode function instead of holding a reference on each node instance - this saves memory.
	cout << endl << "depth: " << BinaryTree::calculateDepth(tree) << endl;
	
	BinaryTree* balancedTree = BinaryTree::balance(tree);
	BinaryTree::inorder(tree);
	cout << endl << "depth: " << BinaryTree::calculateDepth(tree);
	
	
	
	delete tree;



	while (1);
	return 0;
}


