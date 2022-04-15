#include<iostream>
#include<utility>
#include<string>

	void askHowNames() {
		std::cout << "How many names would you like to enter?" << std::endl;
	}
	void askGetNames(int num) {
		std::cout << "Enter name #" << num + 1 << ": ";
	}
	void printError(std::string thing) {
		std::cout << "You get a invalid " << thing << ".Please, try again." << std::endl;
	}

int enterNumOfNames() {// Get the number of names, check it and return.
	while (true) {
		int numNames{ 0 };
		std::cin >> numNames;
		
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			printError("number");
		}
		else {
			std::cin.ignore(32767, '\n');
			return numNames;
		}
	}
}	
void getName(int numNames, std::string *name) {// Get names to string array
	for (int num = 0; num < numNames; ++num) {
		askGetNames(num);
		std::cin >> name[num];
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			printError("name");
		}
		else {
			std::cin.ignore(32767, '/n');
		}
	}
}


void sortArray(std::string *name, int numNames) {// Bubble sort string name array

	int startName{0};
	int iter{ 0 };

	for (int iteration = 0; iteration < numNames - 1; ++iteration) {
		startName = iteration;
		iter = iteration + 1;
		for (int index = 1; index < numNames; ++index) {
			if (name[index] < name[index - 1]) {
				startName = index;
			}
		}
		std::swap(name[iteration], name[startName]);
		if (name[startName] == name[0])
			break;
	}
}

void printNames(std::string *name, int numNames) {// Print names with number of names
	std::cout << "Here is your sorted list:" << std::endl;
	for (int number = 0; number < numNames; ++number) {
		std::cout << "Name #" << number + 1 << ": " << *(name+number) << std::endl;
	}
}