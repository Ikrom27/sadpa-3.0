#pragma once
#include <string>
#include "Book.h"
#include <forward_list>
#include <vector>
#include <list>


class HeshTable
{
private:
	std::list<Book*> *table;
	float loadFactor;
	int size;
	int elements;
public:
	HeshTable();
	int hashFunc(char* GroupNumber);
	void add(char* key, Book value);
	void remove(char* GroupNumber);
	Book* find(char* GroupNumber);
	std::list<Book*> find_by_index(int index);
	void resizeTable(int key);
	void updateSize();
	void info();
};

