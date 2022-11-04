#pragma once
#include <string>
#include "Book.h"
#include <forward_list>
#include <vector>
#include <list>


class HeshMap
{
private:
	std::list<Book> *table;
	int size;
	int elements;
	int collision;
public:
	HeshMap();
	int heshFunc(char* key);
	void add(char* key, Book element);
	Book find(char* key);
	void remove(char* key);
	void update();
	void resize(int size_);

	void showTable();
	void info();
};

