#include "stdafx.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "RBTree.h"

using namespace std;
using std::string;

RBTree::RBTree()
{
	numberOfElements = 0;

	sentinel.color = 'B';
	sentinel.parent = sentinel.leftSon = sentinel.rightSon = root = &sentinel;

	// character strings used in displaying tree
	topCorner = bottomCorner = vertical = "  ";
	topCorner[0] = 218; bottomCorner[1] = 196;
	bottomCorner[0] = 192; bottomCorner[1] = 196;
	vertical[0] = 179;
}


RBTree::~RBTree()
{
	numberOfElements = 0;
	deleteTree(root); // one by one
}

void RBTree::deleteTree(RBNode *node)
{
	if (node != &sentinel)
	{
		deleteTree(node->leftSon);  
		deleteTree(node->rightSon);  
		delete node;              
	}
}

void RBTree::buildRandomly(int enteredAmount)
{
	for (int i = 0; i < enteredAmount; i++)
		addNode((rand() % 101) + 0);
}

void RBTree::buildFromFile()
{
	string filename = "test.txt";
	ifstream file(filename); //opening an input stream for file test.txt
							 /*checking whether file could be opened or not. If file does not exist or don't have read permissions, file
							 stream could not be opened.*/
	string helper;
	int help;
	if (file)
	{
		while (!file.eof()) // poprawka
		{
			file >> helper;
			help = stoi(helper);
			addNode(help);
		}
		file.close();
	}
	else
		cout << "\nCouldn't open " << filename << " to read\n";
}

void RBTree::printTree(string text1, string text2, RBNode *node)
{
	if (root == &sentinel)
		cout << "Tree is empty...\n";
	else
	{
		string text;

		if (node != &sentinel)
		{
			text = text1;
			if (text2 == topCorner)
				text[text.length() - 2] = ' ';
			printTree((text + vertical), topCorner, node->rightSon);

			text = text.substr(0, text1.length() - 2);
			cout << text << text2 << node->color << ":" << node->key << endl;

			text = text1;
			if (text2 == bottomCorner)
				text[text.length() - 2] = ' ';
			printTree((text + vertical), bottomCorner, node->leftSon);
		}
    }
}

void RBTree::display()
{
	printTree("", "", root);
}

bool RBTree::findKey(int enteredValue) // gotowe
{
	RBNode *helper = new RBNode();
	helper = root;
	bool found = false;

	if (root == &sentinel)
		cout << "Tree is empty...\n";
	else 
	{
		while ((found == false) && (helper != &sentinel))
		{
			if (helper->key != enteredValue)
			{
				found = true;
			}
			else
			{
				if (helper->key < enteredValue)
					helper = helper->rightSon;
				else
					helper = helper->leftSon;
			}
		}
	}

	if (found == 0)
		cout << "Element not found...\n";
	else
	{
		if (helper->color == 'R')
			cout << "color: red\n";
		else cout << "color: black\n";
	}

	return found;
}

RBNode * RBTree::returnSuccesor(RBNode * node)
{
	RBNode *helper = NULL;

	if (node->rightSon != &sentinel)
	{
		helper = node->rightSon;
		while (helper->leftSon != &sentinel)
		{
			helper = helper->leftSon;
		}
	}
	else 
	{
		helper = node->leftSon;
		while (helper->leftSon != NULL)
			helper = helper->leftSon;
	}
	return helper;
}

void RBTree::addNode(int enteredValue)
{
	RBNode *newNode = new RBNode();
	newNode->leftSon = newNode->rightSon = &sentinel;
	newNode->parent = root;
	newNode->key = enteredValue;
	newNode->color = 'R';
	numberOfElements++;
	cout << "sentinel: "<<  &sentinel << endl;
	cout << "root: " << root << endl;
	if (root == &sentinel)
	{
		root = newNode;
		newNode->parent = &sentinel;
		cout << "add node: " << newNode << endl;
	}
	else
	{
		while (true)
		{
			if (enteredValue < newNode->parent->key)
			{
				if (newNode->parent->leftSon == &sentinel) // if there is empty spot
				{
					newNode->parent->leftSon = newNode; 
					break;
				}
				else newNode->parent = newNode->parent->leftSon; // going to the next level of the tree
			}
			else
			{
				if (newNode->parent->rightSon == &sentinel) // if there is empty spot
				{
					newNode->parent->rightSon = newNode;
					break;
				}
				else newNode->parent = newNode->parent->leftSon;
			}
		} // end of while loop

		treeAddFix(newNode); // fixing tree -> checking red-black tree conditions
	}
}

void RBTree::deleteNode(int searchedKey)
{
	
	if (root == NULL)
	{
		cout << "Can't delete anything - tree is empty!\n";
	}
	else
	{
		RBNode *helper = new RBNode();
		RBNode *helper1 = new RBNode();
		helper = root;

		if (findKey(searchedKey))
		{
			while ((helper != &sentinel) && (helper->key !=searchedKey))
			{
					helper = (searchedKey < helper->key) ? helper->leftSon : helper->rightSon;
			}

			if ((helper->leftSon == &sentinel) || (helper->rightSon == &sentinel))
			{
				if (helper->leftSon == &sentinel) // deleting node hasn't left son
				{
					if (helper->color == 'B')
					{
						if ((helper->parent->color == 'R') && (helper->rightSon->color == 'R'))
						{
							helper->rightSon->color = 'B';
						}
					}
					helper = helper->rightSon;
				}
				else // deleting node hasn't right son
				{
					if (helper->color == 'B')
					{
						if ((helper->parent->color == 'R') && (helper->leftSon->color == 'R'))
						{
							helper->leftSon->color = 'B';
						}
					}
					helper = helper->leftSon;
				}
			} // odtad ma dwoch synow 
			else
			{
				if (helper->rightSon == returnSuccesor(helper)) // 3 
				{
					helper1 = helper->rightSon;
					if (helper1->color == 'B')
						helper1->rightSon->color = 'B';
					helper1->leftSon = helper->leftSon;
					helper1->color = helper->color;
					helper = helper1;
				}
				else // 4 
				{

				}
			}
		}
		else
			cout << "Can't find the searched key!\n";
	}
}

void RBTree::treeAddFix(RBNode * newNode)
{
	RBNode *grandpa = new RBNode();
	RBNode *uncle = new RBNode();

	if (root == newNode)
	{
		newNode->color = 'B';
	}
	else
	{
		while ((newNode->parent != &sentinel) && (newNode->parent->color == 'R'))
		{
			grandpa = newNode->parent->parent;
			cout << "grandpa: " << grandpa;
			if (newNode->parent == grandpa->leftSon) 
			{
				if (grandpa->rightSon != &sentinel) // if right uncle exists
				{
					uncle = grandpa->rightSon;
					if (uncle->color == 'R')
					{
						newNode->parent->color = 'B';
						grandpa->color = 'R';
						uncle->color = 'B';
						
						newNode = grandpa; // goes higher then
					}
				}
				else // no uncle so we should rotate tree
				{

					if (newNode->parent->rightSon == newNode)
					{
						newNode = newNode->parent;
						leftRotation(newNode);
					}
					newNode->parent->color = 'B';
					grandpa->color = 'R';
					rightRotation(grandpa);
				}
			}
			else // mirror situation :) parent is right son of grandpa
			{
				if (grandpa->leftSon != &sentinel)
				{
					uncle = grandpa->leftSon;
					if (uncle->color == 'R')
					{
						newNode->parent->color = 'B';
						uncle->color = 'B';
						grandpa->color = 'R';
						newNode = grandpa;
					}
				}
				else // no uncle so we should rotate tree
				{
					if (newNode->parent->leftSon == newNode)
					{
						newNode = newNode->parent;
						rightRotation(newNode);
					}
					newNode->parent->color = 'B';
					grandpa->color = 'R';
					leftRotation(grandpa);
				}
			}
			root->color = 'B'; // fixing root
		}
	}

}

void RBTree::leftRotation(RBNode * A)
{
	RBNode * B, *p;

	B = A->rightSon;
	if (B != &sentinel)
	{
		p = A->parent;
		A->rightSon = B->leftSon;
		if (A->rightSon != &sentinel) A->rightSon->parent = A;

		B->leftSon = A;
		B->parent = p;
		A->parent = B;

		if (p != &sentinel)
		{
			if (p->leftSon == A) p->leftSon = B; else p->rightSon = B;
		}
		else root = B;
	}
	/*RBNode *helper;

	helper = node->rightSon;
	node->leftSon = helper->leftSon;
	helper->leftSon->parent = node;
	helper->parent = node->parent;

	if (node->parent == &sentinel)
	{
		root = helper;
	}
	else if (node == node->parent->leftSon)
		node->parent->leftSon = helper;
	else
		node->parent->rightSon = helper;
	helper->leftSon = node;
	node->parent = helper;
	//cout << "Can't do operation...\n"; poszukaj warunku kiedy sie nie da i przeanalizuj wszystko
	*/
}

void RBTree::rightRotation(RBNode * A)
{
	RBNode * B, *p;

	B = A->leftSon;
	if (B != &sentinel)
	{
		p = A->parent;
		A->leftSon = B->rightSon;
		if (A->leftSon != &sentinel) A->leftSon->parent = A;

		B->rightSon = A;
		B->parent = p;
		A->parent = B;

		if (p != &sentinel)
		{
			if (p->rightSon == A) p->rightSon = B; else p->leftSon = B;
		}
		else root = B;
	}
	/*RBNode *helper;

	helper = node->leftSon;
	node->leftSon = helper->rightSon;
	helper->rightSon->parent = node;
	helper->parent = node->parent;

	if (node->parent == &sentinel)
	{
		root = helper;
	}
	else if (node == node->parent->rightSon)
		node->parent->rightSon = helper;
	else
		node->parent->leftSon = helper;
	helper->rightSon = node;
	node->parent = helper;
	//else cout << "Can't do operation...\n";*/
}
