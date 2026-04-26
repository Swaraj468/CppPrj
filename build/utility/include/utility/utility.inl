#pragma once
#include<vector>

template<typename T>
void temp(T msg, bool newLine) {
	std::cout << msg;
	if (newLine) {
		std::cout << std::endl;
	}
}



template<typename T>
void printVector(const std::vector<T> vect) {
	for (T i : vect) {
		std::cout << i << " ";
	}
}

template<typename T>
T sum(T t) {
	return t;
}

template<typename ArgOne, typename... ArgTwo>
ArgOne sum(ArgOne one, ArgTwo... two) {
	return one + sum(two...);
}
