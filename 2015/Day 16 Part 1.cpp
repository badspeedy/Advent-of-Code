// Advent of Code.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <string>


int box[20];
int combos;
std::string s_input;

struct aunts {
	std::string item1;
	int qty1;
	std::string item2;
	int qty2;
	std::string item3;
	int qty3;
	bool no1;
	bool no2;
	bool no3;
};

struct items {
	std::string item;
	int qty;
};

items item[10] = { {"children", 3},
	{"cats", 7},
	{"samoyeds", 2},
	{"pomeranians", 3},
	{"akitas", 0},
	{"vizslas" , 0},
	{"goldfish", 5},
	{"trees", 3},
	{"cars", 2},
	{"perfumes", 1} };

int main() {
	aunts aunt[500];

	std::ifstream file("Day 16.txt");

	while (file.is_open()) {
		int line = 0;
		std::size_t locate1, locate2, locate3, locate4, locate5, locate6;
		while (std::getline(file, s_input)) {
			aunt[line].no1 = false;
			aunt[line].no2 = false;
			aunt[line].no3 = false;
			locate1 = s_input.find(':') + 2;
			locate2 = s_input.find(':', locate1) + 2;
			locate3 = s_input.find(',') + 2;
			locate4 = s_input.find(':', locate3) + 2;
			locate5 = s_input.find(',', locate4) + 2;
			locate6 = s_input.find(':', locate5) + 2;

			aunt[line].item1 = s_input.substr(locate1, (locate2 - locate1 - 2));
			aunt[line].qty1 = std::stoi(s_input.substr(locate2, locate3 - locate2 - 2));
			aunt[line].item2 = s_input.substr(locate3, locate4 - locate3 - 2);
			aunt[line].qty2 = std::stoi(s_input.substr(locate4, locate5 - locate4 - 2));
			aunt[line].item3 = s_input.substr(locate5, locate6 - locate5 - 2);
			aunt[line].qty3 = std::stoi(s_input.substr(locate6));

			line++;

		}

		file.close();
	}

	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 10; j++) {
			if (aunt[i].item1 == item[j].item) {
				if (aunt[i].qty1 == item[j].qty) {
					aunt[i].no1 = true;
				}
			}
			if (aunt[i].item2 == item[j].item) {
				if (aunt[i].qty2 == item[j].qty) {
					aunt[i].no2 = true;
				}
			}
			if (aunt[i].item3 == item[j].item) {
				if (aunt[i].qty3 == item[j].qty) {
					aunt[i].no3 = true;
				}
			}
		}

	}

	for (int i = 0; i < 500; i++) {
		if (aunt[i].no1 == true && aunt[i].no2 == true && aunt[i].no3 == true) {
			std::cout << i+1 << std::endl;
		}
	}


	return 0;
}
