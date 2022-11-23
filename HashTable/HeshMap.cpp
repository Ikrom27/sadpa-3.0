#include "HeshMap.h"

HeshMap::HeshMap()
{
	size = 19;
	elements = 0;
	table = new std::list<Element>[size];
}

int HeshMap::heshFunc(char* key)
{
	int index = 0;
	for (int i = 0; i < sizeof(key); i++) {
		if (key[i] != '-') {
			index += abs(key[i]) + abs(key[sizeof(key)-i]);
		}
	}
	if (size < index) { resize(index); }
	return index;
}

void HeshMap::add(char* key, int noteNum)
{
	int index = heshFunc(key);
	if (table[index].size() == 1) {
		collision += 1;
	}
	if (table[index].size() == 0) {
		update();
	}
	Element newElem;
	memcpy(newElem.key, key, 11);
	newElem.noteNum = noteNum;
	table[index].push_back(newElem);
}

Element HeshMap::find(char* key)
{
	std::list<Element> Node = table[heshFunc(key)];
	for (Element i : Node) {
		if (strcmp(key, i.key) == 0) {
			return i;
		}
	}
	std::cout << "Запись не найдена";
}

int HeshMap::findNum(char* key)
{
	return find(key).noteNum;
}

void HeshMap::remove(char* key)
{
	std::list<Element> node = table[heshFunc(key)];
	std::list<Element> newNode;
	Element element = find(key);
	for (auto& i : node) {
		if ((std::string)(i.key) == (std::string)(key)) {
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
	std::list<Element>* extendedTable = new std::list<Element>[size_ * 2];
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
