#include "stdafx.h"
#include "Table.h"
#include <fstream>
#include <iostream>

using namespace std;

Table::Table()
{
	ptr = new int[numberOfElements];
}


Table::~Table() //destructor
{
	numberOfElements = 0;
	delete [] ptr;
}

//member functions definition
void Table::fillRandomly(int enteredSize)
{
	numberOfElements = enteredSize;
	ptr = new int[numberOfElements];
	for (int i = 0; i < numberOfElements; i++)
	{
		ptr[i] = (rand()%101)+0;
	}
	cout << "Ilosc elementow : " << numberOfElements;
}

void Table::fillFromFile() 
{
	string filename = "test.txt";
	ifstream file(filename); //opening an input stream for file test.txt
							 /*checking whether file could be opened or not. If file does not exist or don't have read permissions, file
							 stream could not be opened.*/
	string helper;
	int helpp;
	if (file)
	{
		while (!file.eof()) //!file.eof()
		{
			file >> helper;
			helpp = stoi(helper);
			addAtTheEnd(helpp);
		}
		file.close();
	}
	else cout << "\nCouldn't open " << filename << " for reading\n";

	display();
}

void Table::display()
{
	if (numberOfElements == 0)
		cout << "Table is empty!" << endl;
	else
	{
		cout << "\nThe whole content of an array:" << endl;
		for (int i = 0; i < numberOfElements; i++)
		{
			cout << "t[" << i << "]:" << ptr[i] << " ";
		}
	}
}

void Table::reallocation()
{
	/* ~ How it works ~ (real implementation)
	Allocate a new array larger than the existing array size (operator new[]),
	Copy all of the array’s contents into the new array (operator =),
	Free the old array (operator delete[]),
	Additionally, if the type has any constructors or destructors, these are also called for every element during relocation.
	*/
	int *reallocTable = new int[numberOfElements];
	for (int i = 0; i < numberOfElements; i++)
	{
		reallocTable[i] = ptr[i];
	}
	delete[] ptr; // free the old array
 	ptr = new int[numberOfElements];
	for (int i = 0; i < numberOfElements; i++)
	{
		ptr[i] = reallocTable[i];
	}
	delete[] reallocTable;
}

void Table::searchValue(int enteredValue)
{
	bool valueExists = false;
	for (int i = 0; i < numberOfElements; i++)
	{
		if (ptr[i] == enteredValue)
		{
			valueExists = true;
			break;
		}
	}
	if (valueExists)
		cout << "Searched value exists! " << endl;
	else cout << "Searched value doesn't exist! " << endl;
}

// adding functions 
void Table::addAtTheBeginning(int enteredValue)
{
	numberOfElements++;
	// making bigger the whole table to enter new value
	reallocation();
	for (int i = numberOfElements - 1; i > 0; i--) 
	{
		ptr[i] = ptr[i - 1];
	}
	ptr[0] = enteredValue;
}

void Table::addAtTheEnd(int enteredValue)
{
	numberOfElements++;
	reallocation();
	ptr[numberOfElements-1] = enteredValue;
}

void Table::addInTheMiddle(int enteredValue, int indexWhere)
{
	// popraw wrzuca smiecia, jak na koniec dodaje , jest blad z dodawaniem na koniec i wgl !
	if (indexWhere > numberOfElements)
		cout << "Element is out of range!" << endl;
	if (indexWhere == 0)
		addAtTheBeginning(enteredValue);
	else if (indexWhere == numberOfElements)
		addAtTheEnd(enteredValue);
	// sprawdz warunki 
	else if ((indexWhere > 0) && (indexWhere < numberOfElements))
	{
		numberOfElements++;
		reallocation();

		for (int i = numberOfElements - 1; i > indexWhere; i--)
		{
			ptr[i] = ptr[i - 1];
		}
		ptr[indexWhere] = enteredValue;
	}
}

//deleting functions 
void Table::deleteFromBeginning()
{
	for (int i = 0; i < numberOfElements; i++)
	{
		ptr[i] = ptr[i + 1];
	}
	numberOfElements--;
	reallocation();
}

void Table::deleteFromEnd()
{
	ptr[numberOfElements - 1] = 0;
	numberOfElements--;
	reallocation();
}

void Table::deleteFromMiddle(int indexWhere)
{
	for (int i = indexWhere; i < numberOfElements; i++)
	{
		ptr[i] = ptr[i + 1]; // sprawdz
	}
	numberOfElements--;
	reallocation();
}