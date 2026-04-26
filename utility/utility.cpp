#include<vector>
#include<algorithm>
#include<iostream>
#include "header.h"
#include "Defination.h"
 std::vector<int> generateRandomNumbers(int numberOfNumbers) {
	std::vector<int>randomNumbers;
	std::srand(std::time(nullptr));
	for (int i = 0; i < 12; i++) {
		int number = std::rand() % 100 - 50;
		randomNumbers.push_back(number);
		std::cout << number << " ";
	}
	return randomNumbers;
}
 std::vector<int> BubbleSort(std::vector<int>& vectorSort) {
	for (int j = 0; j < vectorSort.size() - 1; j++) {
		for (int k = 0; k < vectorSort.size() - j - 1; k++) {
			if (vectorSort[k] > vectorSort[k + 1]) {
				std::swap(vectorSort[k], vectorSort[k + 1]);
			}
		}
	}
	return vectorSort;
}

 class Student {
 public:
	 Student(std::string name, int id, int year) : name{ name }, id{ id }, year{ year } {
		 std::cout << "Custom constructor" << std::endl;

	 }

	 Student(const char* name, int StudentId, int StudentYear) : Student{ std::string{name}, StudentId, StudentYear } {
		 std::cout << "raw char constructor called" << std::endl;
	 }
	 ~Student() {
		 std::cout << "Student" << name << " is destructed" << std::endl;
	 }


	 std::string name;
	 int id;
	 int year;
 private:
	 int secrete;

 };
 void printMain() {
	std::vector<int>randomNumbers = generateRandomNumbers(5);
	BubbleSort(randomNumbers);
	std::cout << "the sorted number is: " << std::endl;
	//for (int j = 0; j < randomNumbers.size(); j++) {
	//	for (int k = j + 1; k < randomNumbers.size(); k++) {
	//		if (randomNumbers[j] > randomNumbers[k]) {
	//			std::swap(randomNumbers[j], randomNumbers[k]);
	//		}
	//	}
	//}

	
	for (int n : randomNumbers) {
		std::cout << n << " ";
	}
}