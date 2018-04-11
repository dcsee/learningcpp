#pragma once
#include<vector>

class BinaryTree
{
public:
	BinaryTree(int data);
//	NaryTree();
	~BinaryTree();

	int getBranchFactor();
	int getData();
	void addNode(int data);
	static void inorder(BinaryTree* tree);
	static int calculateDepth(BinaryTree* tree);
	BinaryTree* getLeftBranch();
	BinaryTree* getRightBranch();
	static BinaryTree* balance(BinaryTree* tree);

	void setLeftBranch(BinaryTree* tree);
	void setRightBranch(BinaryTree* tree);

private:
	int branchFactor;
	int data;
//	std::vector<NaryTree*> branches;
	BinaryTree* leftBranch;
	BinaryTree* rightBranch;

};

