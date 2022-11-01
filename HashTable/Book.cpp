#include "Book.h"

Book::Book()
{
}

Book::Book(std::string path)
{

	std::ifstream ft(path, std::ios::out);

	if (!ft)
	{
		std::cout << "файл не открыт";
		return;
	}

	while (!ft.eof()) {
		ft.getline(GroupNumber, sizeof(GroupNumber));
		ft >> NumberOfStudents;
		ft.get();
		ft.getline(DirectionCode, sizeof(DirectionCode));
		ft.getline(ProfileCode, sizeof(ProfileCode));
	}
	ft.close();
}

void create_bin_file(std::string fnameText, std::string fnameBin)
{
	Book file;

	std::ifstream ft;
	std::ofstream fb;

	ft.open(fnameText, std::ios::out);
	fb.open(fnameBin, std::ios::out | std::ios::binary);

	if (!ft || !fb)
	{
		std::cout << "файл не открыт";
		return;
	}

	while (!ft.eof()) {
		ft.getline(file.GroupNumber, sizeof(file.GroupNumber));
		ft >> file.NumberOfStudents;
		ft.get();
		ft.getline(file.DirectionCode, sizeof(file.DirectionCode));
		ft.getline(file.ProfileCode, sizeof(file.ProfileCode));
		fb.write((char*)&file, sizeof(Book));
	}

	ft.close();
	fb.close();
}

void out_bin_file(std::string fnameBin)
{
	Book file;
	std::ifstream fb(fnameBin, std::ios::out | std::ios::binary);
	if (!fb)
	{
		std::cout << "файл не открыт";
		return;
	}
	fb.read((char*)&file, sizeof(Book));
	while (!fb.eof()) {
		std::cout << file.GroupNumber << std::endl;
		std::cout << file.NumberOfStudents << std::endl;
		std::cout << file.DirectionCode << std::endl;
		std::cout << file.ProfileCode << std::endl;
		fb.read((char*)&file, sizeof(Book));
	}
	fb.clear();
	fb.close();
}

void out_bin_file_by_key(std::string fnameBin, int key)
{
	Book file;
	std::ifstream fb;
	int note_num=1;

	std::cout << "Print note number: "; std::cin >> note_num;

	fb.open(fnameBin, std::ios::out | std::ios::binary);
	if (!fb)
	{
		std::cout << "файл не открыт";
		return;
	}
	fb.read((char*)&file, sizeof(Book));

	while (!fb.eof()) {
		if (key == note_num) {
			std::cout << file.GroupNumber << std::endl;
			std::cout << file.NumberOfStudents << std::endl;
			std::cout << file.DirectionCode << std::endl;
			std::cout << file.ProfileCode << std::endl;
			return;
		}
		note_num += 1;
		fb.read((char*)&file, sizeof(Book));
	}

	std::cout << "¬ведено неверное значение";

	fb.clear();
	fb.close();
	return;
}

void delete_note_by_key(std::string bin_path, int key)
{
	std::fstream fs(bin_path, std::ios_base::in | std::ios_base::out | std::ios_base::binary);

	Book last_record;

	fs.seekg(-static_cast<int>(sizeof(Book)), std::ios_base::end);
	if (fs.tellg() != -1)
	{
		fs.read(reinterpret_cast<char*>(&last_record), sizeof(Book));
	}
	else
	{
		throw std::runtime_error("No information in file");
	}
	fs.seekg(0);
	int n = 1;
	Book card_buffer;
	int current_position = 0;
	while (true)
	{
		current_position = fs.tellg();
		fs.read(reinterpret_cast<char*>(&card_buffer), sizeof(Book));
		if (n == key)
		{
			fs.seekg(current_position);
			fs.write(reinterpret_cast<char*>(&last_record), sizeof(Book));
			fs.close();
			return;
		}
		if (fs.eof())
		{
			fs.close();
			throw std::runtime_error("Can't find record with such key");
		}
		n += 1;
	}
}
