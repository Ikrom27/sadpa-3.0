#pragma once
#include <string>
#include <iostream>
#include <fstream>

struct Book
{
	char GroupNumber[11];
	int NumberOfStudents;
	char DirectionCode[9];
	char ProfileCode[11];
	Book();
	Book(std::string path);
	void display(Book& file);
	Book* writeToBook(std::fstream& ft);
	void create_bin_file(std::string fnameText, std::string fnameBin);
	void openCheck(std::fstream& ft);
	void out_bin_file(std::string fnameBin);
	Book& search(std::fstream& fb, Book& file, int key);
	void out_bin_file_by_key(std::string fnameBin, int key);
	void delete_note_by_key(std::string bin_path, int key);
	Book& getLastRecord(std::fstream& fs, Book& last_record);
};
