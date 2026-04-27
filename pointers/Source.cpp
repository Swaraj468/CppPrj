#include<iostream>
#include<vector>
#include<algorithm>
//#include "Header.h"
#include <memory>

void printInt(int val) {
	//unique ptr the usage is very similar to raw pointer.
	std::unique_ptr<int> intUniquePtr = std::make_unique<int>(5);

	//it doesnot allow to copy but it allows to move. the std::move transfers the ownership of the raw pointer internally to the other one.
	std::unique_ptr<int> anotherPtr = std::move(intUniquePtr);
	std::cout << intUniquePtr << std::endl;
	if (intUniquePtr) {
		std::cout << *intUniquePtr << std::endl;
	}
	anotherPtr.reset();
	//it is used when the pointer is supose to be shared. Use unique whenever possible
	//in real practice though, shared_pointer is used a lot.
	//a texture, any assets that is suppose to be shared between different objects, shared is a good choice.
	//unique pointer is more suited for single private ownership.
	//shared ptr are thread safe.
	std::shared_ptr<int> anotherShared = std::make_shared<int>(5); //ref count = 1
	std::shared_ptr<int> intShared = anotherShared; //ref count = 2


	// weak ptr? used in conjunction with the shared pointer.
	std::weak_ptr<int> intWeakPtr = anotherShared; //ref count doesnot increment, ref count = 2
	std::weak_ptr<int> emptyWeak;
	emptyWeak = intWeakPtr;

	// copy is fine in weak pointer
	std::weak_ptr<int> copyWeakPtr = intShared;

	//reset only reset the weak ptr itself, make it expired, do not affect ref count, do not make other weak pointer expired.
	intWeakPtr.reset();


	//lock generates another shared pointer. multi threading
	std::shared_ptr<int> anotherSShared = intWeakPtr.lock(); //ref = 2 now cause 
	std::cout << anotherSShared << std::endl;
	//std::cout << intWeakPtr.lock() << std::endl;




	anotherShared.reset(); //ref count = 1

	if (intWeakPtr.expired()) {
		std::cout << "The weak pointer is expired" << std::endl;
	}
	else {
		std::cout << "The weak pointer is alive" << std::endl;
	}
	intShared.reset();
	if (intWeakPtr.expired()) {
		std::cout << "The weak pointer is expired" << std::endl;
	}
	else {
		std::cout << "The weak pointer is alive" << std::endl;
	}
	//	int* rawInt = new int{ 5 };
	//	int* anotherPtr = rawInt;
	//
	//	delete  rawInt;
	//	rawInt = nullptr;
	//	std::cout << anotherPtr << std::endl;
	//}
}

int main() {
	while (true) {
		printInt(5);
	}
	int* array = new int[5]; //making a pointer that points to an array created on the heap.
	delete[] array; //remember to delete with the [] if you are free the entire array.

}



//int x = 5;
//int* xPtr = &x;
//int* xPtr3 = &x;
//int** PtrToxPtr = &xPtr;
//void* xPtr2 = &x;

//float floatVar = 12.5;
//float* myFloat = &floatVar;

//std::cout << xPtr << std::endl;
//std::cout << xPtr2 << std::endl;
//std::cout << myFloat << std::endl;
//std::cout << *myFloat << std::endl;
////std::cout << *(int*)xPtr2 << std::endl; this is called raw style casting but in this type casting we don't check if the type is not compatible
//std::cout << *static_cast<int*>(xPtr2) << std::endl;
//int intArray[5] = { 1, 2, 3, 4, 5 };

//for (int i = 0; i < sizeof(intArray) / sizeof(int); i++) {
//	std::cout << *(intArray + i) << std::endl;
//}
//defineing a custom type (class), what it has.
//class Student
//{
//public:
//	Student(const std::string& studentName, int studentID, int studentYear)//a consturctor is a function that has no return type, and has the same name as the class
//
//		: name{ studentName }, ID{ studentID }, year{ studentYear }	// initializer more performant than doing the assignement in the body of the constructor
//	{
//		std::cout << "custom constructor called" << std::endl;
//	}
//		Student(const char* rawStringName, int  studentID, int studentYear) //you can create different constructors. as long as their signature are different.
//		:Student{ std::string{rawStringName}, studentID, studentYear }//: name{rawStringName}, ID{studentID}, year{studentYear}
//	{
//		std::cout << "raw char constructor called" << std::endl;
//	}
//	~Student() {
//		std::cout << "student " << name << " is destructed" << std::endl;
//	}
//	//an accessor
//	void sayHello() const
//	{
//		std::cout << "Say Hi " << name << std::endl;
//	}
//
//	//mutator, modifier 
//	void IncrementYear() {
//		year++;
//		switch (year)
//		{
//		case 1:
//			std::cout<< name<< " is in freshman"<<std::endl;
//			break;
//		case 2:
//			std::cout << name << " is in 2nd year" << std::endl;
//			break;
//		case 3:
//			std::cout << name << " is in junior year" << std::endl;
//			break;
//		case 4:
//			std::cout << name << " is in last year" << std::endl;
//			break;
//
//		default:	
//			std::cout << name << " is graduated" << std::endl;
//			break;
//		}
//	}
//	bool IsGraduated() const
//	{
//		return year > 4;
//	}
//	//setters
//	void setId(int newID) {
//		if (newID < 0) 
//		{
//			std::cout << "Wrong Id Value, it should be positive";
//			return;
//		}
//		ID = newID;
//	}
//	//getters often paired with const, meaning you are not altering the state of the member variables. you can no 
//	int GetId() const 
//	{
//		return ID;
//	}
//
//	std::string name;
//	
//
//
//private://to have the member in the private section. and provide the private function to alter the value. you can no longer change the values either
//	const int ID;//a student should have the ID.  //always consider const for member variables as well
//    int year; 
//	int secrate;
//};
//
//int main() {
//	const Student studentOne{ "Sam", 12111470, 1 }; //making an instance of student. a real variable.
//	std::cout << studentOne.GetId() << std::endl;
//	
//	//studentOne.sayHello();
//	//while (!studentOne.IsGraduated()) {
//	//	studentOne.IncrementYear();
//	//}
//	//studentOne.setId(1);
//	//std::cout << studentOne.GetId() << std::endl;
//
//}
//
////
////class Car {
////public:
////	const std::string carName;
////	
////	const std::string carType;
////	Car(const std::string& Name, int Number, const std::string& Type, const std::string& Gas)
////		: carName{ Name }, RegNumber{ Number }, carType{ Type }, TotalGas{Gas}
////	{
////		std::cout << "Constructor is created" << std::endl;
////	}
////
////	~Car() {
////		std::cout << "Constructor is dead" << std::endl;
////	}
////	//void setRegNumber(int num) {
////	//	if (num < 0) {
////	//		std::cout << "The car number is wrong";
////	//		return;
////	//	}
////	//	RegNumber = num;
////	//}
////	//int GetRegNumber() const
////	//{
////	//	return RegNumber;
////	//}
////
////	void setTotaGas(std::string haas) {
////		if (haas.empty() && std::all_of(haas.begin(), haas.end(), ::isdigit)) {
////			std::cout << "Wrong value for the game" << std::endl;
////			return;
////		}
////		TotalGas = haas;
////	}
////	std::string GetTotalGas() const
////	{
////		return TotalGas;
////	}
////private:
////	const int RegNumber;
////	std::string TotalGas;
////};
////
////int main() {
////	 Car carOne{ "Toyota Fortuner", 5634, "SUV", "65 liters"};
////	//carOne.setRegNumber(-1);
////	//std::cout << carOne.GetRegNumber() << std::endl;
////
////	carOne.setTotaGas("");
////	std::cout << carOne.GetTotalGas() << std::endl;
////
////
////}
//
