#include "stdafx.h"
#include "Heap.h"
#include "Table.h"
#include <iostream>
#include <fstream>
#include <string>


#include <ctime>
using namespace std;

Heap::Heap()
{
	currentSize = 0;
	table = new Table();
}

Heap::~Heap()
{
	for (int i = 0; i < table->numberOfElements; i++)
	{
		table->numberOfElements--;
		table->deleteFromEnd();
	}
	currentSize = 0;
}

void Heap::buildRandomly(int length)
{
	for (int i = 0; i < length ; i++)
	{
		table->addAtTheEnd(rand() % 100);
	}
	currentSize = length;
	heapify();
}

void Heap::buildFromFile()
{
	string filename = "test.txt";
	ifstream file(filename); //opening an input stream for file test.txt
							 /*checking whether file could be opened or not. If file does not exist or don't have read permissions, file
							 stream could not be opened.*/
	string helper;
	int help;
	if (file)
	{
		while (!file.eof()) 
		{
			file >> helper;
			help = stoi(helper);
			insert(help); 
		}
		file.close();
		heapify();
	}
	else
		cout << "\nCouldn't open " << filename << " to read\n";
}

int Heap::findParent(int i)
{ 
	return floor((i - 1) / 2);
	// parent at index floor((i − 1) ∕ 2).
}

// to get index of left child of node at index i
int Heap::findLeft(int i) 
{ 
	return (2 * i + 1); 
}

// to get index of right child of node at index i
int Heap::findRight(int i)
{ 
	return (2 * i + 2); 
}

void Heap::insert(int enteredKey)
{
	currentSize++;
	table->addAtTheEnd(enteredKey);

	// fixing heap property
	heapify();
	
}

void Heap::extract(int enteredKey)
{
	Table *helper = new Table();

	if (table->numberOfElements == 0)
		cout << "The tree is empty! \n";
	else
	{
		int i = 0;
		while ((table->ptr[i] != enteredKey) && (table->numberOfElements > 0))
		{
			helper->addAtTheEnd(table->ptr[i]);
			table->deleteFromBeginning();
		}

		if (table->ptr[i] == enteredKey)
		{
			table->deleteFromBeginning();
			currentSize--;
		}

		for (int i = 0; i < helper->numberOfElements; i++)
		{
			
			table->addAtTheEnd((helper->ptr[i]));
		}
		heapify();
	}
}

void Heap::fixHeap(int i)
{
	int helper, right, left, heapify;
	left = findLeft(i);// get the left child
	right = findRight(i);// get the right child

					  //if one of the children is bigger than the index

	if (left <= currentSize && table->ptr[left] > table->ptr[i])
		heapify = left;
	else heapify = i;
	if (right <= currentSize && table->ptr[right] > table->ptr[heapify])
		heapify = right;
	if (heapify != i)
	{
		helper = table->ptr[heapify];
		table->ptr[heapify] = table->ptr[i];
		table->ptr[i] = helper;
		fixHeap(heapify);
	}
}

//kopcowanie dla kazdego elementu
void Heap::heapify()
{
	for (int i = (table->numberOfElements) - 1; i >= 0; --i)
	{
		fixHeap(i);
	}
}

void Heap::search(int enteredKey)
{
	Table *helper = new Table();

	if (table->numberOfElements == 0)
		cout << "The tree is empty! \n";
	else
	{
		int i = 0;
		while ((table->ptr[i] != enteredKey) && (currentSize > 0))
		{
			helper->addAtTheEnd(table->ptr[i]);
			table->deleteFromBeginning();
		}

		if (table->ptr[i] == enteredKey)
		{
			cout << "The key has been found! \n";
		}

		for (int i = 0; i < helper->numberOfElements; i++)
		{
			table->addAtTheEnd((helper->ptr[i]));
		}
		heapify();
	}
}

void Heap::display(char * text1, char * text2) // string text1, string text2
{
	cout << "Displaying the whole tree: \n";
	for (int i = 0; i < currentSize; i++)
	{
		cout << "[" << i << "]:" << table->ptr[i] << " ";
	}
	cout << endl;
	
	cout << table->ptr[0] << endl;
	int level = 0;
	int iterator = 1;
	int condition;

	while (iterator < currentSize )
	{
		level++;
		condition = iterator + pow(2, level);
		while ((iterator < condition) && (iterator < currentSize))
		{
			cout << table->ptr[iterator] << " ";
			iterator++;
		}
		cout << endl;
	}
}

