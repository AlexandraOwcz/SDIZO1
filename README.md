# SDIZO1
Project task 1: Testing the efficiency of adding, deleting, and retrieving items in different data structures


// PL
Cel ćwiczenia: należało zaimplementować oraz dokonać pomiaru czasu działania operacji takich jak dodawanie elementu, usunięcie elementu i wyszukanie elementu dla następujących struktur danych:
a) Tablica,
b) Lista,
c) Kopiec binarny
d) Drzewo czerwono- czarne

Sposób wykonania pomiarów czasu:
Do pomiarów czasu wykorzystałam metodę dostępną w standardzie C++11, ponieważ jest ona łatwa w użyciu. Należało dołączyć do programu bibliotekę chrono: 
#include <chrono>, z której używamy std::chrono::high_resolution_clock , co będzie mierzyć czas (duration) funkcji. Przykładowy fragment kodu, w którym dana funkcja została zastosowana:

cin >> choice;high_resolution_clock::time_point t1 = high_resolution_clock::now();

table->addAtTheBeginning(choice);

high_resolution_clock::time_point t2 = high_resolution_clock::now();

auto duration = duration_cast<microseconds>(t2 - t1).count();

cout << "\nThe time of adding element to array: " << duration;

Dodatkowo, aby ułatwić pracę wyniki pomiarów czasu zapisywane są automatycznie do pliku tekstowego test_time.txt

