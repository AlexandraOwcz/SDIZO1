#pragma once
#include <string>

using namespace std;

class Table
{
private: 
	int* ptr;
	friend class Heap;
public:
	int numberOfElements;
	Table();
	~Table();
	// member functions declaration
	void fillRandomly(int enteredSize);
	void fillFromFile();
	void display();
	void reallocation();
	void searchValue(int enteredValue);
	// adding functions
	void addAtTheBeginning(int enteredValue);
	void addAtTheEnd(int enteredValue);
	void addInTheMiddle(int enteredValue, int indexWhere);
	//deleting functions
	void deleteFromBeginning();
	void deleteFromEnd();
	void deleteFromMiddle(int indexWhere);
};

