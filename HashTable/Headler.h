#include "Book.h"
#include "HeshMap.h"
#include <iostream>


class Headler : protected BookHeadler {
private:
	HeshMap Table;
public:
	Headler(std::string path);
	void createBinFile();
	void outBinFile();
	void printInxex(char* key);
	void remove(char* key);
	void findByKey(char* key);
	void HeshMapInfo();
	void HeshMapShow();
};