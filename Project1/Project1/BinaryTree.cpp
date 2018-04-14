#include "BinaryTree.h"
#include <vector>
#include<iostream>
using namespace std;


BinaryTree::BinaryTree(int data) {
	this->root = new BinaryTreeNode(data);
	this->maxDepth = 1;
}


BinaryTree::~BinaryTree() {
	delete root;
}


int BinaryTree::getDepth() {
	return this->maxDepth;
}


BinaryTreeNode* BinaryTree::getRoot() {
	return this->root;
}


int BinaryTree::addNode(BinaryTreeNode* currentNode, int data) {
	if (data < currentNode->getData()) {
		BinaryTreeNode* leftBranch = currentNode->getLeftBranch();
		if (leftBranch == NULL) {
			currentNode->setLeftBranch(new BinaryTreeNode(data));
			return 1;
		}
		else {
			return 1 + addNode(leftBranch, data);
		}
	}
	else {
		BinaryTreeNode* rightBranch = currentNode->getRightBranch();
		if (rightBranch == NULL) {
			currentNode->setRightBranch(new BinaryTreeNode(data));
			return 1;
		}
		else {
			return 1 + addNode(rightBranch, data);
		}
	}
}


void BinaryTree::insert(int data) {
	int depth = 1 + addNode(root, data);
	this->maxDepth = (depth > maxDepth) ? depth : maxDepth;
}

BinaryTreeNode::BinaryTreeNode(int data)
{
	this->data = data;
	this->leftBranch = NULL;
	this->rightBranch = NULL;
}


BinaryTreeNode::~BinaryTreeNode()
{
	if (this->leftBranch != NULL) {
		delete this->leftBranch;
	}
	if (this->rightBranch != NULL) {
		delete this->rightBranch;
	}
}


int BinaryTreeNode::getData() {
	return this->data;
}


BinaryTreeNode* BinaryTreeNode::getLeftBranch() {
	return this->leftBranch;
}


BinaryTreeNode* BinaryTreeNode::getRightBranch() {
	return this->rightBranch;
}


void BinaryTreeNode::setLeftBranch(BinaryTreeNode* tree) {
	this->leftBranch = tree;
}

void BinaryTreeNode::setRightBranch(BinaryTreeNode* tree) {
	this->rightBranch = tree;
}


int BinaryTree::calculateDepth(BinaryTreeNode* tree) {
	int depth = 0;
	if (tree != NULL) {
		depth = 1;
		int leftDepth = BinaryTree::calculateDepth(tree->getLeftBranch());
		int rightDepth = BinaryTree::calculateDepth(tree->getRightBranch());
		depth += (leftDepth > rightDepth) ? leftDepth : rightDepth;
	}
	return depth;
}


int BinaryTree::calculateDepth(BinaryTree* tree) {
	return BinaryTree::calculateDepth(tree->getRoot());
}


void BinaryTree::inorder(BinaryTreeNode* tree) {

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


void BinaryTree::inorder(BinaryTree* tree) {
	BinaryTree::inorder(tree->getRoot());
}



void fillNodeVector(BinaryTreeNode* tree, vector<BinaryTreeNode*> &nodeVector) {
	//fill the vector using inorder traversal, to get all the nodes
	//in sorted order

	if (tree == NULL) {
		return;
	}
	fillNodeVector(tree->getLeftBranch(), nodeVector);
	nodeVector.push_back(tree);
	fillNodeVector(tree->getRightBranch(), nodeVector);
}

BinaryTreeNode* buildSortedTree(vector<BinaryTreeNode*> &nodeVector, int start, int end) {
	
	if (start > end) {
		return NULL;
	}

	//progressively make the median of the vector be the new root for each subtree
	int middle = (start + end) / 2;
	BinaryTreeNode* newRoot = nodeVector[middle];
	newRoot->setLeftBranch(
		buildSortedTree(nodeVector, start, middle - 1)
	);
	newRoot->setRightBranch(
		buildSortedTree(nodeVector, middle + 1, end)
	);
	return newRoot;
}


void BinaryTree::balance(BinaryTreeNode* tree) {

	vector<BinaryTreeNode*> nodeVector = vector<BinaryTreeNode*>();
	fillNodeVector(tree, nodeVector);
	buildSortedTree(nodeVector, 0, nodeVector.size() - 1);
}

void BinaryTree::balance(BinaryTree* tree) {
	BinaryTree::balance(tree->getRoot());
}