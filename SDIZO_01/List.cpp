#include "stdafx.h"
#include "List.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//konstruktor
List::List()
{
	head = NULL; tail = NULL;
}

//destruktor
List::~List()
{
	// delete the node one by one from the head
	Component *component = new Component();

	component = head;
	while (component != NULL)
	{
		head = head->next;
		delete component;
		component = head;
	}

	// resets the head and tail node 
	head = tail = NULL;
}

void List::fillRandomly(int enteredSize)
{
	for (int i = 0; i < enteredSize; i++)
		pushBack((rand()%1001)+0);
}

void List::fillFromFile()
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
			pushBack(help);
		}
		file.close();
	}
	else 
		cout << "\nCouldn't open "<< filename << " to read\n";
}

void List::display()
{
	// mozliwe, ze to do poprawki
	Component *component = new Component();
	component = head;
	if (head)
	{
		bool end = false;
		while (component)
		{
			cout << component->key << " ";
			component = component->next;
		}
	}
	else cout << "The list is empty! " << endl;

	delete [] component;
}

bool List::findKey(int findKey)
{
	Component *component = head;
	bool found = false;

	while (component && (found != true)) 
	{
		if((component->key) != findKey)
			component = component->next;
		else
		{
			found = true;
			cout << "\nThe key value has been found!\n";
		}
	}
	return found;
}

// adding functions
void List::pushBack(int enteredValue)
{
	Component *newComponent = new Component();
	newComponent->key = enteredValue;

	if (!head)
	{
		head = newComponent;
		tail = head;
	}
	else
	{
		newComponent->previous = tail;
		newComponent->next = NULL;
		if (tail)
			tail->next = newComponent;
		tail = newComponent;
		if (!head)
			newComponent->key = enteredValue;
	}
}

void List::pushFront(int enteredValue)
{
	Component *newComponent = new Component();

	newComponent->key = enteredValue;
	newComponent->previous = NULL;
	newComponent->next = head;
	if (head)
		head->previous = newComponent;
	head = newComponent;
	if (!tail)
		tail = head;
}

void List::pushMiddle(int enteredValue, int keyWhere)
{
	//inserting new element before the element at the specified position :)
	Component *component = new Component();

	component = head;
	cout << "w funkcji pushMiddle: \n";
	cout << "czy znaleziony klucz: " << findKey(keyWhere);
	
	if (findKey(keyWhere))
	{
		if ((head->key == keyWhere) || (tail->key == keyWhere))
		{
			if (head->key == keyWhere)
			{
				pushFront(enteredValue);
			}
			else
			{
				pushBack(enteredValue);
			}
		}
		else
		{
			Component *newComponent = new Component();
			while (component->key != keyWhere) 
			{
				component = component->next; 
			}
			
			newComponent->key = enteredValue;
			newComponent->next = component; 
			newComponent->previous = component->previous; 
			newComponent->previous->next = newComponent;
			component->previous = newComponent;
			
		}
	}
	else cout << "\nKey not found!\n";
}

// deleting functions
void List::popFront()
{
	Component *helper;
	helper = head;

	if (!head)
		cout << "The list is already empty!" << endl;
	else
	{
		if (head == tail) // one element
			head = tail = NULL;
		else
		{
			(helper->next)->previous = NULL;
			head = helper->next;
		}
	}
	delete[] helper;
}

void List::popBack() 
{
	Component *helper = tail;

	if (!head) // empty list
		cout << "The list is already empty!" << endl;
	else
	{
		if (head == tail) // one element in the list
		{
			head = tail = NULL;
		}
		else
		{
			tail = helper->previous;
			tail->next = NULL;
		}
	}
	delete helper;
}

void List::popMiddle(int enteredValue)
{
	Component *helper = head;
	Component *previousComponent;

	if (findKey(enteredValue))
	{
		if (head->key == enteredValue)
		{
			popFront();
		}
		else
		{
			if (tail->key == enteredValue)
			{
				popBack();
			}
			else
			{
				while (helper)
				{
					if ((helper->key) != enteredValue)
						helper = helper->next;
					else
					{
						previousComponent = helper;
						previousComponent = previousComponent->previous;
						helper = helper->next;

						previousComponent->next = helper;
						helper->previous = previousComponent;
					}
				}
			}
		}
	}
	else cout << "\nCan't delete anything- value not found!\n";
}
