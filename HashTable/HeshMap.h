#pragma once
#include <string>
#include "Book.h"
#include <forward_list>
#include <vector>
#include <list>


struct Element {
	char key[11];
	int noteNum;
};


class HeshMap
{
private:
	std::list<Element> *table;
	int size;
	int elements;
	int collision;
public:
	HeshMap();
	int heshFunc(char* key);
	void add(char* key, int noteNum);
	Element find(char* key);
	int findNum(char* key);
	void remove(char* key);
	void update();
	void resize(int size_);

	void showTable();
	void info();
};

