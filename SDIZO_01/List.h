#pragma once

class Component
{
public:
	Component *next, *previous;
	int key;
	Component() 
	{
		key = 0; next = NULL; previous = NULL;
	}
};

class List
{
private:
	Component * head, *tail;
public:
	// member functions declaration
	List();
	~List();
	void fillRandomly(int enteredSize);
	void fillFromFile();
	void display();
	bool findKey(int findKey);
	// adding functions
	void pushBack(int enteredValue); // dodaje na ko�cu listy kopi� przekazanego argumentu
	void pushFront(int enteredValue);
	void pushMiddle(int enteredValue, int findValue);
	// deleting functions
	void popFront(); // deleting first element of the list
	void popBack();
	void popMiddle(int enteredValue); // usuwa wszystkie elementy r�wne argumentowi wartosc
};

