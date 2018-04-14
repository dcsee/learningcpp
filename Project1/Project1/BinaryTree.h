#pragma once
#include<vector>

class BinaryTreeNode;

class BinaryTree
{
public:
	BinaryTree(int data);
	~BinaryTree();
	int getDepth();
	BinaryTreeNode* getRoot();
	void insert(int data);
	static void inorder(BinaryTree* tree);
	static void balance(BinaryTree* tree);
	static int calculateDepth(BinaryTree* tree);

private:
	int maxDepth;
	BinaryTreeNode * root;
	int addNode(BinaryTreeNode* currentNode, int data);
	static void inorder(BinaryTreeNode* tree);
	static void balance(BinaryTreeNode* tree);
	static int calculateDepth(BinaryTreeNode* tree);
};

class BinaryTreeNode
{
public:
	BinaryTreeNode(int data);
	~BinaryTreeNode();

	int getData();
	BinaryTreeNode* getLeftBranch();
	BinaryTreeNode* getRightBranch();

	void setLeftBranch(BinaryTreeNode* tree);
	void setRightBranch(BinaryTreeNode* tree);

private:
	BinaryTreeNode* leftBranch;
	BinaryTreeNode* rightBranch;
	int data;
};

