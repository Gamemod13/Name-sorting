#include<iostream>
#include<string>
#include<utility>
#include"sort.h"

int main() {
	askHowNames();
	int num{ 0 };
	num = enterNumOfNames();
	std::string* name = new std::string[num];
	getName(num, name);
	sortArray(name, num);
	printNames(name, num);
	delete[] name;
	name = nullptr;
	return 0;
}