#include <string>
#include <fstream>
#include <iostream>


struct Book
{
	char GroupNumber[10];
	int NumberOfStudents;
	char DirectionCode[8];
	char ProfileCode[10];
};

Book getSchedule(std::string path)
{
	Book Schedule;
	std::ifstream ft(path, std::ios::out);
	if (!ft)
	{
		std::cout << "файл не открыт";
		return;
	}
	while (!ft.eof()) {
		ft.getline(Schedule.GroupNumber, sizeof(Schedule.GroupNumber));
		ft >> Schedule.NumberOfStudents;
		ft.get();
		ft.getline(Schedule.DirectionCode, sizeof(Schedule.DirectionCode));
		ft.getline(Schedule.ProfileCode, sizeof(Schedule.ProfileCode));
	}
	ft.close();
	return Schedule;
}