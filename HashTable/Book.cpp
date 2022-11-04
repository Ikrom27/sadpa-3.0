#include "Book.h"

bool Book::equal(Book file)
{
	if ((strcmp(GroupNumber, file.GroupNumber) == 0) and
		(strcmp(DirectionCode, file.DirectionCode) == 0) and
		(strcmp(ProfileCode, file.ProfileCode) == 0) and
		(NumberOfStudents == file.NumberOfStudents))
	{
		return true;
	}
	return false;
}

BookHeadler::BookHeadler(std::string path_)
{
	fnameText = path_;
	fnameBin = path_ + ".bin";
}

void BookHeadler::createBinFile()
{
	Book file;
	std::ifstream ft(fnameText, std::ios::out);
	std::ofstream fb(fnameBin, std::ios::out | std::ios::binary);
	while (!ft.eof()) {
		writeToBook(ft, file);
		fb.write((char*)&file, sizeof(Book));
	}
	ft.close();
	fb.close();
}

void BookHeadler::outBinFile()
{
	Book file;
	std::ifstream fb(fnameBin, std::ios::out | std::ios::binary);
	fb.read((char*)&file, sizeof(Book));
	while (!fb.eof()) {
		display(file);
		fb.read((char*)&file, sizeof(Book));
	}
	fb.close();
}

void BookHeadler::find(int key)
{
	Book file;
	std::ifstream fb(fnameBin, std::ios::out | std::ios::binary);
	fb.read((char*)&file, sizeof(Book));
	while (!fb.eof()) {
		if (key == file.NoteNumber) {
			display(file);
			fb.close();
			return;
		}
		fb.read((char*)&file, sizeof(Book));
	}
	fb.close();
}

void BookHeadler::find(char* key)
{
	Book file;
	std::ifstream fb(fnameBin, std::ios::out | std::ios::binary);
	fb.read((char*)&file, sizeof(Book));
	while (!fb.eof()) {
		if (strcmp(key, file.GroupNumber) == 0) {
			display(file);
			fb.close();
			return;
		}
		fb.read((char*)&file, sizeof(Book));
	}
	fb.close();
}

void BookHeadler::removeNote(char* key)
{
	Book last_record = getLastRecord();
	Book buffer;

	std::fstream fs(fnameBin, std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	int current_position = 0;
	while (!fs.eof())
	{
		current_position = fs.tellg();
		fs.read((char*)&buffer, sizeof(Book));
		if (strcmp(key, buffer.GroupNumber) == 0)
		{
			fs.seekg(current_position);
			fs.write((char*)&last_record, sizeof(Book));
			fs.close();
			return;
		}
	}
	fs.close();
}

void BookHeadler::writeToBook(std::ifstream& ft, Book& file)
{
	ft >> file.NoteNumber;
	ft.get();
	ft.getline(file.GroupNumber, sizeof(file.GroupNumber));
	ft >> file.NumberOfStudents;
	ft.get();
	ft.getline(file.DirectionCode, sizeof(file.DirectionCode));
	ft.getline(file.ProfileCode, sizeof(file.ProfileCode));
}

void BookHeadler::display(Book& file)
{
	std::cout << file.NoteNumber << std::endl;
	std::cout << file.GroupNumber << std::endl;
	std::cout << file.NumberOfStudents << std::endl;
	std::cout << file.DirectionCode << std::endl;
	std::cout << file.ProfileCode << std::endl;
}

Book BookHeadler::getLastRecord()
{
	Book lastRecord;
	std::fstream fs(fnameBin, std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	fs.seekg((-1)*(sizeof(Book)), std::ios_base::end);
	fs.read(reinterpret_cast<char*>(&lastRecord), sizeof(Book));
	fs.seekg(0);
	return lastRecord;
}
