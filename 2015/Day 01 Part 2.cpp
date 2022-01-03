#include <fstream>
#include <iostream>
#include <string>



std::string s_input;

int main() {

	int floor;

	std::ifstream file("Day 1.txt");

	while (file.is_open()) {
		while (std::getline(file, s_input)) {
			for (int i = 0; i < s_input.size(); i++) {
				if (s_input[i] == '(') {
					floor++;
				}
				else {
					floor--;
				}
				if (floor == -1) {
					std::cout << i << std::endl;
					return 0;
				}
			}
		}

		file.close();
	}

	std::cout << floor << std::endl;

	return 0;
}