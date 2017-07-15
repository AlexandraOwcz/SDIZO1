#pragma once

class Table;

class Heap
{
private: 
	int currentSize;
	Table *table;
public:
	Heap();
	~Heap();

	void buildFromFile();
	void buildRandomly(int length);
	// -----------------
	int findParent(int i);
	int findLeft(int i);
	int findRight(int i);


	void insert(int enteredKey);
	void extract(int enteredKey);
	void fixHeap(int i);
	void heapify();
	void search(int enteredKey);
	void display(char * text1, char * text2);
};

