#pragma once
#include<vector>
#include<string>
#include"Defination.h"

UTILITY_API std::vector<int> generateRandomNumbers(int numberOfNumbers);
UTILITY_API std::vector<int> BubbleSort(std::vector<int>& vectorSort);
UTILITY_API void printMain();
template<typename T>
void temp(T msg, bool newLine);
#include"utility.inl"

template<typename T>
void printVector(const std::vector<T> vect);
#include"utility.inl"

template<typename T>
T sum(T t);
#include"utility.inl"

template<typename ArgOne, typename... ArgTwo>
ArgOne sum(ArgOne one, ArgTwo... two);
#include"utility.inl"



