#include "HeshMap.h"

HeshMap::HeshMap()
{
	size = 100;
	elements = 0;
	table = new std::list<Book>[size];
}

int HeshMap::heshFunc(char* key)
{
	int index = 0;
	for (int i = 0; i < sizeof(key); i++) {
		if (key[i] != '-') {
			index += abs(key[i]);
		}
	}

	/*
	int group = (key[5] - 48) * 10 + key[6] - 48;
	int year = (key[8] - 48) * 10 + key[9] - 48;
	int index = group + year;
	*/
	if (size < index) { resize(index); }
	return index;
}

void HeshMap::add(char* key, Book element)
{
	int index = heshFunc(key);
	if (table[index].size() == 1) {
		collision += 1;
	}
	if (table[index].size() == 0) {
		update();
	}
	table[heshFunc(key)].push_back(element);
}

Book HeshMap::find(char* key)
{
	std::list<Book> Node = table[heshFunc(key)];
	for (Book i : Node) {
		if (strcmp(key, i.GroupNumber) == 0) {
			return i;
		}
	}
	std::cout << "Запись не найдена";
}

void HeshMap::remove(char* key)
{
	std::list<Book> node = table[heshFunc(key)];
	std::list<Book> newNode;
	Book element = find(key);
	for (auto& i : node) {
		if (!i.equal(element)) {
			newNode.push_back(i);
		}
	}
	table[heshFunc(key)] = newNode;
	elements--;
}

void HeshMap::update()
{
	elements++;
	float loadFactor = (float)elements / (float)size;
	if (loadFactor > 0.75) { resize(size); };
}

void HeshMap::resize(int size_)
{
	std::list<Book>* extendedTable = new std::list<Book>[size_ * 2];
	memcpy(extendedTable, table, size_ * sizeof(int));
	table = extendedTable;
	size = size_;
}

void HeshMap::showTable()
{
	for (int i = 0; i < size; i++) {
		std::cout << i << " - [" << table[i].size() << "]\n";
	}
}

void HeshMap::info()
{
	std::cout << "Информация о хэш-таблице: " << std::endl;
	std::cout << "Общий размер размер таблицы - " << size << std::endl;
	std::cout << "Количество заполненых яцеек - " << elements << std::endl;
	float f = (float)elements / (float)size;
	std::cout << "Коэфицент нагрузки - " << f << std::endl;
	std::cout << "Коллизий - " << collision << std::endl;
}
