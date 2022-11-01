#include <iostream>
#include <fstream>
#include "HeshTable.h"
#include "Book.h"

void testHeshT() {
    Book Schedule("test.txt");
    HeshTable table;

    table.add(Schedule.GroupNumber, Schedule); // key="» ¡Œ-07-21"

    
    Book test1("test1.txt");
    table.add(test1.GroupNumber, test1);

    table.
}


int main()
{
    setlocale(LC_ALL, "rus");


    system("pause");
}
