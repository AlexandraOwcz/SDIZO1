// SDIZO_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Table.h"
#include "List.h"
#include "Heap.h"
#include "RBTree.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

#include <chrono>

using namespace std;
using namespace std::chrono;

void mainMenu();
void tableMenu();
void listMenu();
void heapMenu();
void rbTreeMenu();
void writeToFile(long long duration);


int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	mainMenu();

	system("pause"); 
	return 0;
}

//all menu 
void mainMenu()
{
	int choice;
	cout << endl << endl;
	cout << "          Main Menu  " << endl;
	cout << " ----------------------------- " << endl;
	cout << " 1. Table " << endl;
	cout << " 2. List " << endl;
	cout << " 3. Binary Heap " << endl;
	cout << " 4. RB Tree " << endl;
	cout << " Enter number of your choice: ";
	cin >> choice;

	system("cls");
	switch (choice)
	{
	case 1:
	{
		tableMenu();
	}
	break;
	case 2:
	{
		listMenu();
	}
	break;
	case 3: 
	{
		heapMenu();
	}
	break;
	case 4:
	{
		rbTreeMenu();
	}
	default:
		cout << "Operation not found! Try again! " << endl; 
		break;
	}
}

void tableMenu()
{
	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;
	int choice;
	Table *table;
	table = new Table();

	cout << endl;
	cout << "            Table Menu  " << endl;
	cout << " ----------------------------- " << endl;
	cout << " 1. Fill randomly " << endl;
	cout << " 2. Fill from file " << endl;
	cout << " 3. Display table " << endl;
	cout << " 4. Search value " << endl;
	cout << " 5. Add at the beginning " << endl;
	cout << " 6. Add at the end " << endl;
	cout << " 7. Add in the middle " << endl;
	cout << " 8. Delete from the beginning " << endl;
	cout << " 9. Delete from the end " << endl;
	cout << " 10. Delete from the middle " << endl;
	while (true)
	{
		cout << " Enter number of your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter number of elements that you want: " << endl;
			cin >> choice;
			table->fillRandomly(choice);
		}
		break;
		case 2:
		{
			table->fillFromFile();
		}
		break;
		case 3:
		{
			table->display();
		} break;
		case 4:
		{
			cout << "Enter value that you search: " << endl;
			cin >> choice;
			t1 = high_resolution_clock::now();
			table->searchValue(choice);
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		}
		break;
		case 5:
		{
			cout << "Enter value that you want to add: " << endl;
			cin >> choice;

			t1 = high_resolution_clock::now();
			table->addAtTheBeginning(choice);
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		} break;
		case 6:
		{
			cout << "Enter value that you want to add: " << endl;
			cin >> choice;

			t1 = high_resolution_clock::now();
			table->addAtTheEnd(choice);
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		}break;
		case 7:
		{
			int indexWhere;
			cout << "Enter value that you want to add: ";
			cin >> choice;
			cout << "Enter where to place the element: ";
			cin >> indexWhere;

			t1 = high_resolution_clock::now();
			table->addInTheMiddle(choice, indexWhere);
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		}break;
		case 8:
		{
			t1 = high_resolution_clock::now();
			table->deleteFromBeginning();
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		}break;
		case 9:
		{
			t1 = high_resolution_clock::now();
			table->deleteFromEnd();
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		}break;
		case 10:
		{
			cout << "enter index: " << endl;
			int indexWhere;
			cin >> indexWhere;
			t1 = high_resolution_clock::now();
			table->deleteFromMiddle(indexWhere);
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		}break;
		default:
			cout << "\nYou entered the wrong value! Try again! \n";
			break;
		}
	}
}

void listMenu()
{

	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;

	int choice;
	List *list;
	list = new List();

	cout << endl;
	cout << "            List Menu  " << endl;
	cout << " ----------------------------- " << endl;
	cout << " 1. Fill randomly " << endl;
	cout << " 2. Fill from file " << endl;
	cout << " 3. Display list " << endl;
	cout << " 4. Search value " << endl;
	cout << " 5. Add at the beginning " << endl;
	cout << " 6. Add at the end " << endl;
	cout << " 7. Add in the middle " << endl;
	cout << " 8. Delete from the beginning " << endl;
	cout << " 9. Delete from the end " << endl;
	cout << " 10. Delete from the middle " << endl;

	while (true)
	{
		cout << " Enter number of your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter number of elements that you want: " << endl;
			cin >> choice;
			list->fillRandomly(choice);
		}
		break;
		case 2:
		{
			list->fillFromFile();
		}
		break;
		case 3:
		{
			list->display();
		} break;
		case 4:
		{
			cout << "Enter key that you search: " << endl;
			cin >> choice;
			t1 = high_resolution_clock::now();
			list->findKey(choice);
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);

		}break;
		case 5:
		{
			cout << "Enter key that you want to add: " << endl;
			cin >> choice;
			t1 = high_resolution_clock::now();
			list->pushFront(choice);
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		} break;
		case 6:
		{
			cout << "Enter key that you want to add: " << endl;
			cin >> choice;
			t1 = high_resolution_clock::now();
			list->pushBack(choice);
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		}break;
		case 7:
		{
			int keyWhere;
			cout << "Enter value that you want to add: ";
			cin >> choice;
			cout << "Enter key where to place the element: ";
			cin >> keyWhere;
			t1 = high_resolution_clock::now();
			list->pushMiddle(choice, keyWhere);
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		}break;
		case 8:
		{
			t1 = high_resolution_clock::now();
			list->popFront();
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		}break;
		case 9:
		{
			t1 = high_resolution_clock::now();
			list->popBack();
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		}break;
		case 10:
		{
			cout << "Enter key where you want to delete element: ";
			cin >> choice;
			t1 = high_resolution_clock::now();
			list->popMiddle(choice);
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		}break;
		default:
			cout << "\nYou entered the wrong value! Try again! \n";
			break;
		}
	}
}

void heapMenu()
{

	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;

	int choice;
	Heap *heap;
	heap = new Heap();

	cout << endl;
	cout << "            Heap Menu  " << endl;
	cout << " ----------------------------- " << endl;
	cout << " 1. Fill randomly " << endl;
	cout << " 2. Fill from file " << endl;
	cout << " 3. Display list " << endl;
	cout << " 4. Search value " << endl;
	cout << " 5. Add key " << endl;
	cout << " 6. Delete key " << endl;
	
	while (true)
	{
		cout << " Enter number of your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter number of elements that you want: " << endl;
			cin >> choice;
			heap->buildRandomly(choice);
		}
		break;
		case 2:
		{
			heap->buildFromFile();
		}
		break;
		case 3:
		{
			heap->display("", "");
		} break;
		case 4:
		{
			cout << "Enter key that you search: " << endl;
			cin >> choice;
			t1 = high_resolution_clock::now();
			heap->search(choice);
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		}break;
		case 5:
		{
			cout << "Enter key that you want to add: " << endl;
			cin >> choice;
			t1 = high_resolution_clock::now();
			heap->insert(choice);
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		} break;
		case 6:
		{
			cout << "Enter key that you want to delete: " << endl;
			cin >> choice;
			t1 = high_resolution_clock::now();
			heap->extract(choice);
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		}break;
		default:
			cout << "\nYou entered the wrong value! Try again! \n";
			break;
		}
	}
}

void rbTreeMenu()
{

	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;

	int choice;
	RBTree *rbtree;
	rbtree = new RBTree();

	cout << endl;
	cout << "            Heap Menu  " << endl;
	cout << " ----------------------------- " << endl;
	cout << " 1. Fill randomly " << endl;
	cout << " 2. Fill from file " << endl;
	cout << " 3. Display tree " << endl;
	cout << " 4. Search value " << endl;
	cout << " 5. Add key " << endl;
	cout << " 6. Delete key " << endl;

	while (true)
	{
		cout << " Enter number of your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter number of elements that you want: " << endl;
			cin >> choice;
			rbtree->buildRandomly(choice);
		}
		break;
		case 2:
		{
			rbtree->buildFromFile();
		}
		break;
		case 3:
		{
			rbtree->display();
		} break;
		case 4:
		{
			cout << "Enter key that you search: " << endl;
			cin >> choice;
			t1 = high_resolution_clock::now();
			rbtree->findKey(choice);
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		}break;
		case 5:
		{
			cout << "Enter key that you want to add: " << endl;
			cin >> choice;
			t1 = high_resolution_clock::now();
			rbtree->addNode(choice);
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		} break;
		case 6:
		{
			cout << "Enter key that you want to delete: " << endl;
			cin >> choice;
			t1 = high_resolution_clock::now();
			rbtree->deleteNode(choice);
			t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();

			writeToFile(duration);
		}break;
		default:
			cout << "\nYou entered the wrong value! Try again! \n";
			break;
		}
	}
}

void writeToFile(long long duration)
{
	string filename = "test_time.txt";
	ofstream file;
	file.open("test_time.txt", ios::app);
	if (file)
	{
		cout << duration;
		file << duration << endl;
		file.close();
	}
	else
		cout << "Couldn't open the file " << filename << endl;

}