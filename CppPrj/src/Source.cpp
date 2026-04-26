#include<iostream>
#include<vector>
#include<algorithm>
#include "Header.h"
#include <memory>



//defineing a custom type (class), what it has.
class Student
{
public:
	Student(const std::string& studentName, int studentID, int studentYear)//a consturctor is a function that has no return type, and has the same name as the class

		: name{ studentName }, ID{ studentID }, year{ studentYear }	// initializer more performant than doing the assignement in the body of the constructor
	{
//		// this is a default constructor. if you do not provide any constructor, this will be automatically created. if you do provide a constructor, then default constructor will not be created for you

		std::cout << "custom constructor called" << std::endl;
	}
	Student(const char* rawStringName, int  studentID, int studentYear) //you can create different constructors. as long as their signature are different.
		:Student{ std::string{rawStringName}, studentID, studentYear }//: name{rawStringName}, ID{studentID}, year{studentYear}
	{
		std::cout << "raw char constructor called" << std::endl;
	}
	~Student() {
		std::cout << "student " << name << " is destructed" << std::endl;
	}
	std::string name;
	int ID;
	int year; 
private:
	int secrate;
};


int main() {
	Student studentOne{"Sam", 12111470, 1}; //making an instance of student. a real variable.

	Student studentTwo{"Emily", 002, 2};
	std::vector<Student> students = { studentOne, studentTwo };
	for (Student& student : students) {
		std::cout << "Student name: " << student.name << std::endl;
		std::cout << "Student ID: " << student.ID << std::endl;
		std::cout << "Student year: " << student.year << std::endl;
	}
}


//class Car {
//public:
//
//	std::string carName;
//	int RegNumber;
//	std::string carType;
//	Car(const std::string& Name, int Number, const std::string& Type)
//		: carName{ Name }, RegNumber{ Number }, carType{ Type }
//	{
//		std::cout << "Constructor is created" << std::endl;
//	}
//
//	~Car() {
//		std::cout << "Constructor is dead" << std::endl;
//	}
//	
//};
//
//int main() {
//	Car carOne{ "Toyota Fortuner", 5634, "SUV" };
//	std::vector<Car> caar = { carOne };
//	for (Car cars : caar) {
//		std::cout << cars.carName << std::endl;
//		std::cout << cars.RegNumber << std::endl;
//		std::cout << cars.carType << std::endl;
//
//	}
//}
//
