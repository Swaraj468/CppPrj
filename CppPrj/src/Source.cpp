#include<iostream>
#include<vector>
#include<algorithm>
#include "Header.h"
#include <memory>
//defineing a custom type (class), what it has.
class Student
{
public:
	std::string name;
	int ID;
	int year;
private:
	int secrate;
};


int main() {
	Student studentOne; //making an instance of student. a real variable.
	studentOne.name = "Sam"; //assigning the value for studentOne's member.
	studentOne.ID = 12111470;
	studentOne.year = 1;

	Student studentTwo;
	studentTwo.name = "Emily";
	studentTwo.ID = 002;
	studentTwo.year = 2;

	std::vector<Student> students = { studentOne, studentTwo };
	for (Student& student : students) {
		std::cout << "Student name: " << student.name << std::endl;
		std::cout << "Student ID: " << student.ID << std::endl;
		std::cout << "Student year: " << student.year << std::endl;
	}
}