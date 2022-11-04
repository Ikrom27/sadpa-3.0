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
		Table.add(file.GroupNumber, file);
		printInxex(file.GroupNumber);
		fb.read((char*)&file, sizeof(Book));
	}
	fb.close();
	std::cout << std::endl;
	HeshMapInfo();
}

void Headler::printInxex(char* key) {
	std::cout << "Индекс файла: " << Table.heshFunc(key) << std::endl;
}

void Headler::remove(char* key)
{
	std::cout << "Удаляется следующий файл " << std::endl;
	printInxex(key);
	removeNote(key);
	Table.remove(key);
	std::cout << std::endl;
	HeshMapInfo();
}

void Headler::findByKey(char* key)
{
	Book b = Table.find(key);
	std::cout << "Запись найдена в хэш-таблице: " << std::endl;
	display(b);
	std::cout << "Запись найдена в Файле: " << std::endl;
	find(b.NoteNumber);
}

void Headler::HeshMapInfo()
{
	Table.info();
}

void Headler::HeshMapShow()
{
	Table.showTable();
}

void Headler::menu()
{
	std::string path;
	std::cout << "Введите путь к файлу: ";
	std::cin >> path;

}

void Headler::input()
{
}
