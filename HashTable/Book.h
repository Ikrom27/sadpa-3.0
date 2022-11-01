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
};

void create_bin_file(std::string fnameText, std::string fnameBin);
void out_bin_file(std::string fnameBin);
void out_bin_file_by_key(std::string fnameBin, int key);
void delete_note_by_key(std::string bin_path, int key);
