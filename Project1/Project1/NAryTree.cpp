#include "NAryTree.h"
#include <vector>
#include <queue>
#include<iostream>
using namespace std;


NAryTree::NAryTree(int nodeId, int thresholdDepth) {
	this->root = new NAryTreeNode(nodeId, 1);
	this->thresholdDepth = thresholdDepth;
}

NAryTree::~NAryTree() {
	delete root;
}

NAryTreeNode* NAryTree::getRoot() {
	return this->root;
}



NAryTreeNode::NAryTreeNode(int nodeId, int depth)
{
	this->nodeId = nodeId;
	this->children = std::vector<NAryTreeNode*>();
	this->depth = depth;
}

NAryTreeNode::~NAryTreeNode()
{
	for(int i = 0; i < this->children.size(); i++){
		delete this->children[i];
	}
}

int NAryTreeNode::getNodeId() {
	return this->nodeId;
}

int NAryTreeNode::getDepth() {
	return this->depth;
}

std::vector<NAryTreeNode*> NAryTreeNode::getChildren() {
	return this->children;
}

NAryTreeNode* NAryTree::find(int nodeId) {
	NAryTreeNode* toReturn = NULL;
	if(root->getNodeId() == nodeId){
		return root;
	}
	
	queue<NAryTreeNode*> nodeQueue = queue<NAryTreeNode*>();
	vector<NAryTreeNode*> children = root->getChildren();
	for(NAryTreeNode* child : children){
		nodeQueue.push(child);
	}
	
	while(nodeQueue.size() > 0){
		NAryTreeNode* node = nodeQueue.front();
		nodeQueue.pop();
		if(node->getNodeId() == nodeId){
			cout << "Found node with id " << node->getNodeId() << " matching searched-for id " << nodeId << endl;
			toReturn = node;
			break;
		} else {
			children = node->getChildren();
			for(NAryTreeNode* child : children){
				nodeQueue.push(child);
			}
		}
	}
	return toReturn;
}


void NAryTree::create(int parentId, int childId) {
	
	//1. find the node with parentId. If node not found, say it wasn't found.
	NAryTreeNode* parent = find(parentId);
	if(parent == NULL){
		cout << "Could not create child " << childId << ": parent " << parentId << " not found!" << endl;
	} else {
		//2. check if tree already contains childId. If so, say it already contains that id.
		NAryTreeNode* child = find(childId);
		if(child != NULL){
			cout << "Could not create child " << childId << ": a node with this id alraedy exists!" << endl;
		} else {
			 //3. create a new treenode and add it to the child list of the parent node.
			parent->addChild(childId, thresholdDepth);
		}
	}
}

void NAryTreeNode::addChild(int childId, int thresholdDepth) {
	if(depth < thresholdDepth){
		NAryTreeNode* child = new NAryTreeNode(childId, depth + 1);
		this->children.push_back(child);
	} else {
		cout << "Cannot add child with id " << childId << ", as that would exceed max depth " << thresholdDepth << endl;
	}
}
