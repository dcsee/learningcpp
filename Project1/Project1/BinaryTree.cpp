#include "BinaryTree.h"
#include <vector>
#include<iostream>
using namespace std;


BinaryTree::BinaryTree(int data)
{
	this->data = data;
	this->leftBranch = NULL;
	this->rightBranch = NULL;
}


BinaryTree::~BinaryTree()
{
	if (this->leftBranch != NULL) {
		delete this->leftBranch;
	}
	if (this->rightBranch != NULL) {
		delete this->rightBranch;
	}
}


int BinaryTree::getData() {
	return this->data;
}


int BinaryTree::getBranchFactor() {
	return this->branchFactor;
}


BinaryTree* BinaryTree::getLeftBranch() {
	return this->leftBranch;
}


BinaryTree* BinaryTree::getRightBranch() {
	return this->rightBranch;
}


void BinaryTree::setLeftBranch(BinaryTree* tree) {
	this->leftBranch = tree;
}

void BinaryTree::setRightBranch(BinaryTree* tree) {
	this->rightBranch = tree;
}


void BinaryTree::addNode(int d) {
	if (d < data) {
		if (leftBranch == NULL) {
			leftBranch = new BinaryTree(d);
		}
		else {
			leftBranch->addNode(d);
		}
	} else {
		if (rightBranch == NULL) {
			rightBranch = new BinaryTree(d);
		}
		else {
			rightBranch->addNode(d);
		}
	}
}


int BinaryTree::calculateDepth(BinaryTree* tree) {
	int depth = 0;
	if (tree != NULL) {
		depth = 1;
		int leftDepth = BinaryTree::calculateDepth(tree->getLeftBranch());
		int rightDepth = BinaryTree::calculateDepth(tree->getRightBranch());
		depth += (leftDepth > rightDepth) ? leftDepth : rightDepth;
	}
	return depth;
}



void BinaryTree::inorder(BinaryTree* tree) {

	//go left as far as you can
	//print the current node when you can't go left anymore
	//go right
	//also print the current node once you've 'popped' back up to it

	if (tree != NULL) {

		BinaryTree::inorder(tree->getLeftBranch());
		cout << tree->getData() << " ";
		BinaryTree::inorder(tree->getRightBranch());
	}
	return;
}



void fillNodeVector(BinaryTree* tree, vector<BinaryTree*> &nodeVector) {
	//fill the vector using inorder traversal, to get all the nodes
	//in sorted order

	if (tree == NULL) {
		return;
	}
	fillNodeVector(tree->getLeftBranch(), nodeVector);
	nodeVector.push_back(tree);
	fillNodeVector(tree->getRightBranch(), nodeVector);
}

BinaryTree* buildSortedTree(vector<BinaryTree*> &nodeVector, int start, int end) {
	
	if (start > end) {
		return NULL;
	}

	//progressively make the median of the vector be the new root for each subtree
	int middle = (start + end) / 2;
	BinaryTree* newRoot = nodeVector[middle];
	newRoot->setLeftBranch(
		buildSortedTree(nodeVector, start, middle - 1)
	);
	newRoot->setRightBranch(
		buildSortedTree(nodeVector, middle + 1, end)
	);
	return newRoot;
}

BinaryTree* BinaryTree::balance(BinaryTree* tree) {

	vector<BinaryTree*> nodeVector = vector<BinaryTree*>();
	fillNodeVector(tree, nodeVector);
	return buildSortedTree(nodeVector, 0, nodeVector.size() - 1);
}