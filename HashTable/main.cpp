#include <iostream>
#include <fstream>
#include "HashTable.h"
#include "Book.h"


int main()
{
    setlocale(LC_ALL, "rus");

    Book Schedule("test.txt");
    HashTable table;
    table.add(Schedule);
    table.add(Schedule);
    std::cout << table.hashFunc(Schedule);

    system("pause");
}
