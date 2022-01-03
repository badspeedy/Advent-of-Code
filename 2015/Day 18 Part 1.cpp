#include <fstream>
#include <iostream>
#include <string>

bool current[100][100];
bool update[100][100];

std::string s_input;
std::string working;


int main() {

	int loops = 100;

	std::ifstream file("Day 18.txt");

	while (file.is_open()) {
		int line = 0;
		while (std::getline(file, s_input)) {
			for (int i = 0; i < s_input.size(); i++)
				current[i][line] = (s_input[i] == '#') ? true : false;
			line++;
		}

		file.close();
	}

	for (int i = 0; i < loops; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 100; k++) {
				int lit = 0;

				for (int x = -1; x <= 1; x++) {
					for (int y = -1; y <= 1; y++) {
						if (y == 0 && x == 0) {
							continue;
						}
						else if ((j + x) < 0 || (j + x) > 99 || (k + y) < 0 || (k + y) > 99) {
							continue;
						}
						else if (current[j + x][k + y] == true) {
							lit++;
						}
					}
				}
				if (current[j][k] == true && (lit == 2 || lit == 3)) {
					update[j][k] = true;
				}
				else if (current[j][k] == false && lit == 3) {
					update[j][k] = true;
				}
				else {
					update[j][k] = false;
				}

			}
		}
		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 100; k++) {
				current[j][k] = update[j][k];
			}
		}
	}

	int count = 0;
	for (int i = 0; i < 100;  i++) {
		for (int j = 0; j < 100; j++) {
			count += current[i][j];
		}
	}
	std::cout << count << std::endl;

	return 0;
}