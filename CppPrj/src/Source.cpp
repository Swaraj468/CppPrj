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
	void sayHello() {
		std::cout << "Say Hi " << name << std::endl;
	}

	void IncrementYear() {
		year++;
		switch (year)
		{
		case 1:
			std::cout<< name<< " is in freshman"<<std::endl;
			break;
		case 2:
			std::cout << name << " is in 2nd year" << std::endl;
			break;
		case 3:
			std::cout << name << " is in junior year" << std::endl;
			break;
		case 4:
			std::cout << name << " is in last year" << std::endl;
			break;

		default:	
			std::cout << name << " is graduated" << std::endl;
			break;
		}
	}
	bool IsGraduated() {
		return year > 4;
	}
	//setters
	void setId(int newID) {
		if (newID < 0) 
		{
			std::cout << "Wrong Id Value, it should be positive";
			return;
		}
		ID = newID;
	}
	//getters
	int GetId() {
		return ID;
	}

	std::string name;
	


private:
	int ID;
	int year; //to have the member in the private section. and provide the private function to alter the value.
	int secrate;
};


int main() {
	Student studentOne{ "Sam", 12111470, 1 }; //making an instance of student. a real variable.
	studentOne.sayHello();
	while (!studentOne.IsGraduated()) {
		studentOne.IncrementYear();
	}
	studentOne.setId(1);
	std::cout << studentOne.GetId() << std::endl;

}


//class Car {
//public:
//	std::string carName;
//	
//	std::string carType;
//	Car(const std::string& Name, int Number, const std::string& Type, const std::string& Gas)
//		: carName{ Name }, RegNumber{ Number }, carType{ Type }, TotalGas{Gas}
//	{
//		std::cout << "Constructor is created" << std::endl;
//	}
//
//	~Car() {
//		std::cout << "Constructor is dead" << std::endl;
//	}
//	void setRegNumber(int num) {
//		if (num < 0) {
//			std::cout << "The car number is wrong";
//			return;
//		}
//		RegNumber = num;
//	}
//	int GetRegNumber() {
//		return RegNumber;
//	}
//
//	void setTotaGas(std::string haas) {
//		if (haas.empty() && std::all_of(haas.begin(), haas.end(), ::isdigit)) {
//			std::cout << "Wrong value for the game" << std::endl;
//			return;
//		}
//		TotalGas = haas;
//	}
//	std::string GetTotalGas() {
//		return TotalGas;
//	}
//private:
//	int RegNumber;
//	std::string TotalGas;
//};
//
//int main() {
//	Car carOne{ "Toyota Fortuner", 5634, "SUV", "65 liters"};
//	carOne.setRegNumber(-1);
//	std::cout << carOne.GetRegNumber() << std::endl;
//
//	carOne.setTotaGas("");
//	std::cout << carOne.GetTotalGas() << std::endl;
//
//
//}
//
