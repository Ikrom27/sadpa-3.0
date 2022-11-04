#pragma once
#include <string>
#include <ctime>
#include <fstream>


class textGenerator
{
private:
	std::string alphanum = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙİŞß";
	std::string num = "1234567890";
	std::string profiles[4] = {"ÌÎÑÈÒ", "ÂÒ", "ÊÈÑ", "ÂĞ"};
public:
	textGenerator();
	void generateText(std::string path, int limit);
	std::string generateGroupNum();
	std::string generateStudentNum();
	std::string generateDirectionCode();
	std::string generateProfileCode();
};

