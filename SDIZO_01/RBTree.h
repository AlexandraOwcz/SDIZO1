#pragma once
#include "stdafx.h"

#include <string>
using namespace std;

class RBNode
{
public:
	RBNode *parent, *leftSon, *rightSon;
	int key;
	char color;
};

class RBTree
{
private:
	RBNode sentinel;
	string topCorner, bottomCorner, vertical;
	char black; 
	char red;
public:
	RBNode *root;
	int numberOfElements;
	RBTree();
	~RBTree();
	// member methods declaration
	void deleteTree(RBNode *node);
	void buildRandomly(int enteredAmount);
	void buildFromFile();
	bool findKey(int enteredValue);
	RBNode* returnSuccesor(RBNode *node);
	void addNode(int enteredValue);
	void deleteNode(int searchedKey);
	void treeAddFix(RBNode *node);
	void leftRotation(RBNode *node);
	void rightRotation(RBNode *node);
	void printTree(string text1, string text2, RBNode *node);
	void display();
};
