#include "Book.h"

Book::Book()
{
}

Book::Book(std::string path)
{

	std::fstream ft(path, std::ios::out);
	openCheck(ft);
	while (!ft.eof()) {
		ft.getline(GroupNumber, sizeof(GroupNumber));
		ft >> NumberOfStudents;
		ft.get();
		ft.getline(DirectionCode, sizeof(DirectionCode));
		ft.getline(ProfileCode, sizeof(ProfileCode));
	}
	ft.close();
}

void Book::display(Book& file)
{
	std::cout << file.GroupNumber << std::endl;
	std::cout << file.NumberOfStudents << std::endl;
	std::cout << file.DirectionCode << std::endl;
	std::cout << file.ProfileCode << std::endl;
}

Book* Book::writeToBook(std::fstream& ft)
{
	ft.getline(GroupNumber, sizeof(GroupNumber));
	ft >> NumberOfStudents;
	ft.get();
	ft.getline(DirectionCode, sizeof(DirectionCode));
	ft.getline(ProfileCode, sizeof(ProfileCode));
	return this;
}

void Book::create_bin_file(std::string fnameText, std::string fnameBin)
{
	Book* file;
	std::fstream ft(fnameText, std::ios::out);
	std::fstream fb(fnameBin, std::ios::out | std::ios::binary);
	openCheck(fb);
	openCheck(ft);
	while (!ft.eof()) {
		file = writeToBook(ft);
		fb.write((char*)&file, sizeof(Book));
	}
	fb.close();
}

void Book::openCheck(std::fstream& ft)
{
	if (!ft)
	{
		std::cout << "файл не открыт";
		return;
	}
}

void Book::out_bin_file(std::string fnameBin)
{
	Book file;
	std::fstream fb(fnameBin, std::ios::out | std::ios::binary);
	openCheck(fb);
	fb.read((char*)&file, sizeof(Book));
	while (!fb.eof()) {
		display(file);
		fb.read((char*)&file, sizeof(Book));
	}
	fb.clear();
	fb.close();
}

Book& Book::search(std::fstream& fb, Book& file, int key)
{
	int note_num = 1;
	fb.read((char*)&file, sizeof(Book));
	while (!fb.eof()) {
		if (key == note_num) {
			return file;
		}
		note_num += 1;
		fb.read((char*)&file, sizeof(Book));
	}
}

void Book::out_bin_file_by_key(std::string fnameBin, int key)
{
	Book file;
	std::fstream fb(fnameBin, std::ios::out | std::ios::binary);
	openCheck(fb);
	file = search(fb, file, key);
	display(file);
	fb.close();
	return;
}

Book& Book::getLastRecord(std::fstream& fs, Book& last_record)
{
	fs.seekg(sizeof(Book), std::ios_base::end);
	fs.read((char*)&last_record, sizeof(Book));
	fs.seekg(0);
	return last_record;
}

void Book::delete_note_by_key(std::string bin_path, int key)
{
	std::fstream fs(bin_path, std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	openCheck(fs);
	Book last_record = getLastRecord(fs, last_record);

	int n = 1;
	Book card_buffer;
	int current_position = 0;
	while (true)
	{
		current_position = fs.tellg();
		fs.read((char*)&card_buffer, sizeof(Book));
		if (n == key)
		{
			fs.seekg(current_position);
			fs.write((char*)&last_record, sizeof(Book));
			fs.close();
			return;
		}
		n += 1;
	}
}
