#pragma once
#include <string>
#include "Book.h"
#include <forward_list>
#include <vector>
#include <list>


struct node {
	Book value;
	node* next = nullptr;
	node* prev = nullptr;
	bool index = false;
};

class HashTable
{
private:
	std::list<Book*>* Cell = new std::list<Book*>[40];
public:
	HashTable();
	int hashFunc(Book Schedule);
	void add(Book Schedule);
	void remove(Book Schedule);
	void find(Book Schedule);
};

