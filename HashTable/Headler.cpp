#include "Headler.h"


Headler::Headler(std::string path) : BookHeadler(path) {}

void Headler::createBinFile()
{
	BookHeadler::createBinFile();
}

void Headler::outBinFile()
{
	Book file;
	std::ifstream fb(fnameBin, std::ios::out | std::ios::binary);
	fb.read((char*)&file, sizeof(Book));
	while (!fb.eof()) {
		display(file);
		// �������� ���� � ����� ������
		Table.add(file.GroupNumber, find(file.GroupNumber));
		printInxex(file.GroupNumber);
		fb.read((char*)&file, sizeof(Book));
	}
	fb.close();
	std::cout << std::endl;
	HeshMapInfo();
}

void Headler::printInxex(char* key) {
	std::cout << "������ �����: " << Table.heshFunc(key) << std::endl;
}

void Headler::remove(char* key)
{
	std::cout << "��������� ��������� ���� " << std::endl;
	printInxex(key);
	Table.remove(key);
	removeNote(Table.findNum(key));
	std::cout << std::endl;
	HeshMapInfo();
}

void Headler::findByKey(char* key)
{
	long double clock_start = clock();
	int noteNum = Table.findNum(key);
	std::cout << "������ ������� � ���-�������" << std::endl;
	long double clock_end = clock();
	long double sort_time = clock_end - clock_start;
	std::cout << "����� ����������: " << sort_time << "ms" << std::endl;
	std::cout << "������ ������� � �����: " << std::endl;
	Book b = find(noteNum);
	display(b);
}

void Headler::HeshMapInfo()
{
	Table.info();
}

void Headler::HeshMapShow()
{
	Table.showTable();
}
