#pragma once
#include <vector>

class NAryTreeNode;

class NAryTree
{
public:
	NAryTree(int nodeId, int thresholdDepth);
	~NAryTree();
	NAryTreeNode* getRoot();
	void create(int parentId, int childId);
	NAryTreeNode* find(int nodeId);

private:
	int thresholdDepth;
	NAryTreeNode * root;
	static int calculateDepth(NAryTreeNode* tree);
};

class NAryTreeNode
{
public:
	NAryTreeNode(int nodeId, int depth);
	~NAryTreeNode();
	void addChild(int childId, int thresholdDepth);
	int getNodeId();
	int getDepth();
	std::vector<NAryTreeNode*> getChildren();

private:
	std::vector<NAryTreeNode*> children;
	int nodeId;
	int depth;
};

