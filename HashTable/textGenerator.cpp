#include "textGenerator.h"


textGenerator::textGenerator()
{
	srand((unsigned)time(NULL));
}

void textGenerator::generateText(std::string path, int limit)
{
	std::ofstream file(path);
	for (int i = 1; i < limit; i++) {
		file << i << std::endl;
		file << generateGroupNum() << std::endl;
		file << generateStudentNum() << std::endl;
		file << generateStudentNum() << std::endl;
		file << generateDirectionCode() << std::endl;
	}
	file.close();
}

std::string textGenerator::generateGroupNum()
{
	std::string groupNum;
	int k;
	for (int i = 0; i < 4; ++i) { 
		groupNum += alphanum[rand() % 29];
	}
	for (int i = 0; i < 2; ++i) {
		groupNum += "-";
		for (int i = 0; i < 2; ++i) {
			groupNum += num[rand() % 10];
		}
	}
	return groupNum;
}

std::string textGenerator::generateStudentNum()
{
	std::string studentNum;
	studentNum += num[rand() % 10];
	studentNum += num[rand() % 10];
	return studentNum;
}

std::string textGenerator::generateDirectionCode()
{
	std::string directionCode;
	for (int i = 0; i < 3; ++i) {
		for (int i = 0; i < 2; ++i) {
			directionCode += num[rand() % 10];
		}
		directionCode += ".";
	}
	directionCode.pop_back();
	return directionCode;
}

std::string textGenerator::generateProfileCode()
{
	return profiles[rand() % 4];
}
;