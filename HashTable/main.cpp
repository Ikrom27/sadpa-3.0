#include <iostream>
#include <fstream>
#include "HeshMap.h"
#include "Book.h"
#include "Headler.h"
#include <ctime>
#include "textGenerator.h"
#include <Windows.h> 


char* StrToChar(std::string text) {
	char* ch = new char[11];
	for (int i = 0; i < 11; i++) {
		ch[i] = text[i];
	}
	return ch;
}

char* getKey() {
	std::string input;
	std::cout << "Ключ [АААА-00-00]: \n";
	std::cout << "Ответ: ";
	std::cin >> input;
	std::cout << std::endl;
	return StrToChar(input);
}

void commandFind(Headler& test) {
	test.findByKey(getKey());
}

void commandRemove(Headler& test) {
	test.remove(StrToChar(getKey()));
}

int main()
{
    setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//textGenerator gen;
	//gen.generateText("test.txt", 1000);
	std::string input;
	std::cout << "Введите путь к файлу: ";
	std::cin >> input;
	std::cout << std::endl;
	Headler test(input);
	test.createBinFile();
	test.outBinFile();

	while (input != "") {
		test.HeshMapInfo();
		std::cout << std::endl;
		std::cout << "Выберите функцию:\n";
		std::cout << "1 - Поиск по ключу\n";
		std::cout << "2 - Удалиить по ключу\n";
		std::cout << "Ответ: ";
		std::cin >> input;
		std::cout << std::endl;
		if (input == "1") { commandFind(test); };
		if (input == "2") { commandRemove(test); };
	}
}
