#include <fstream>
#include <iostream>
#include <string>


int box[20];
int combos;
std::string s_input;

struct aunts {
	std::string item[3];
	int qty[3];
	bool no[3] = { false };
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
		std::size_t locate[6];
		while (std::getline(file, s_input)) {
			locate[0] = s_input.find(':') + 2;
			locate[1] = s_input.find(':', locate[0]) + 2;
			locate[2] = s_input.find(',') + 2;
			locate[3] = s_input.find(':', locate[2]) + 2;
			locate[4] = s_input.find(',', locate[3]) + 2;
			locate[5] = s_input.find(':', locate[4]) + 2;

			for(int i = 0; i < 6; i+=2) {
				aunt[line].item[i/2] = s_input.substr(locate[i], (locate[i+1] - locate[i] - 2));
				aunt[line].qty[i/2] = std::stoi(s_input.substr(locate[i+1], locate[i+2] - locate[i+1] - 2));
			}
			line++;

		}

		file.close();
	}

	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 3; k++) {
				if (aunt[i].item[k] == item[j].item) {
					if ((aunt[i].item[k] == "cats" || aunt[i].item[k] == "trees") && aunt[i].qty[k] > item[j].qty) {
						aunt[i].no[k] = true;
					}
					else if ((aunt[i].item[k] == "pomeranians" || aunt[i].item[k] == "goldfish") && aunt[i].qty[k] < item[j].qty) {
						aunt[i].no[k] = true;
					}
					else if (aunt[i].qty[k] == item[j].qty) {
						aunt[i].no[k] = true;
					}
				}
			}
		}
	}

	for (int i = 0; i < 500; i++) {
		if (aunt[i].no[0] == true && aunt[i].no[1] == true && aunt[i].no[2] == true) {
			std::cout << i + 1 << std::endl;
		}
	}


	return 0;
}