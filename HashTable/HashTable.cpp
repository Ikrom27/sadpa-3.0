#include "HashTable.h"


HashTable::HashTable()
{

}

int HashTable::hashFunc(Book Schedule)
{
	if (Schedule.GroupNumber[5] >= '0' and Schedule.GroupNumber[6] >= '0' and
		Schedule.GroupNumber[5] <= '9' and Schedule.GroupNumber[6] <= '9') {
		int a = (Schedule.GroupNumber[5] - 48) * 10;
		int b = (Schedule.GroupNumber[6] - 48);
		return a + b;
	}
	else {
		std::cout << "Неверный номер группы";
	}
}

void HashTable::add(Book Schedule)
{
	if (Cell[hashFunc(Schedule)].size() == 0) {
		std::list<Book*> newList;
		newList.push_back(&Schedule);
		Cell[hashFunc(Schedule)] = newList;
	}
	else {
		Cell[hashFunc(Schedule)].push_back(&Schedule);
	}
}

void HashTable::remove(Book Schedule)
{
}

void HashTable::find(Book Schedule)
{
}
