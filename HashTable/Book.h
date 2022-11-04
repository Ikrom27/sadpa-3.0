#pragma once
#include <string>
#include <iostream>
#include <fstream>


struct Book {
	int NoteNumber;
	char GroupNumber[11];
	int NumberOfStudents;
	char DirectionCode[9];
	char ProfileCode[11];
	bool equal(Book file);
};

class BookHeadler{
protected:
	std::string fnameText;
	std::string fnameBin;
public:
	BookHeadler(std::string path);
	void createBinFile();
	void outBinFile();
	void find(int key);
	void find(char* key);
	void removeNote(char* key);

	void writeToBook(std::ifstream& ft, Book& file);
	void display(Book& file);
	Book getLastRecord();
	bool equal(Book& file1, Book& file2);
};
