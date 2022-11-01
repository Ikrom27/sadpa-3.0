#include "HeshTable.h"


HeshTable::HeshTable()
{
	table = new std::list<Book*>[100];
	loadFactor = 0;
	size = 100;
	elements = 0;
}

int HeshTable::hashFunc(char* key)
{
	int group = (key[5] - 48) * 10 + key[6];
	int year = (key[8] - 48) * 10 + key[9];
	int index = group + year;
	if (size < index) { resizeTable(index); }
	return index;
}

void HeshTable::add(char* key, Book value)
{
	std::list<Book*> node = table[hashFunc(key)];
	if (node.size() == 0) {
		updateSize();
		std::list<Book*> newList;
		newList.push_back(&value);
		node = newList;
	}
	else {
		node.push_back(&value);
	}
}

void HeshTable::remove(char* key)
{
	std::list<Book*> Node = table[hashFunc(key)];
	Node.remove(find(key));
}

Book* HeshTable::find(char* key)
{
	std::list<Book*> Node = table[hashFunc(key)];
	for (Book* i : Node) {
		if (i->GroupNumber == key) {
			return i;
		}
	}
}

std::list<Book*> HeshTable::find_by_index(int index)
{
	return table[index];
}

void HeshTable::resizeTable(int size_)
{
	std::list<Book*>* extendedTable = new std::list<Book*>[size_ * 2];
	memcpy(extendedTable, table, size_ * sizeof(int));
	table = extendedTable;
}

void HeshTable::updateSize()
{
	size++;
	elements++;
	loadFactor = elements / size;
	if (loadFactor > 0.75) { resizeTable(size); };
}

void HeshTable::info()
{
	std::cout << "Информация о хэш-таблице: " << std::endl;
	std::cout << "Общий размер размер таблицы - " << size << std::endl;
	std::cout << "Количество заполненых яцеек - " << elements << std::endl;
	std::cout << "Коэфицент нагрузки - " << loadFactor << std::endl;
}
