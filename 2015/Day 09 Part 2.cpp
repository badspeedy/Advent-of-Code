#include <fstream>
#include <iostream>
#include <string>

std::string s_input;

// I renamed all the locations a to h

int convert(char a) {
	if (a == 'a') return 0;
	if (a == 'b') return 1;
	if (a == 'c') return 2;
	if (a == 'd') return 3;
	if (a == 'e') return 4;
	if (a == 'f') return 5;
	if (a == 'g') return 6;
	if (a == 'h') return 7;
	return 9;
}

int main() {
	unsigned int temp[8][8];
	unsigned int work[8][8];
	bool tested[8];
	unsigned int totals[8];

	std::ifstream file("Day 9.txt");

	for (int i = 0; i < 8; i++) temp[i][i] = 0;
	while (file.is_open()) {
		while (std::getline(file, s_input)) {
			temp[convert(s_input[0])][convert(s_input[5])] = (int)std::stoi(s_input.substr(8));
			temp[convert(s_input[5])][convert(s_input[0])] = (int)std::stoi(s_input.substr(8));
		}
		file.close();

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				for (int k = 0; k < 8; k++) {
					work[j][k] = temp[j][k];
				}
			}

			for (int j = 0; j < 8; j++) {
				work[j][j] = 0;
				tested[j] = 0;
			}
			//find min
			int x;
			int y = i;
			unsigned int sum = 0;

			do {
				unsigned int low = 0;
				tested[y] = 1;
				for (int j = 0; j < 8; j++) {
					if (work[y][j] > low) {
						low = work[y][j];
						x = j;
					}
					work[y][j] = 0;
					work[j][y] = 0;
				}
				y = x;
				sum += low;
			} while ((tested[0] != 1) || (tested[1] != 1) || (tested[2] != 1) && (tested[3] != 1) || (tested[4] != 1) || (tested[5] != 1) || (tested[6] != 1) || (tested[7] != 1));
			totals[i] = sum;
		}
		unsigned int output = 0;
		for (int i = 0; i < 8; i++) {
			std::cout << totals[i] << std::endl;
			if (totals[i] > output) {
				output = totals[i];


			}
		}
		std::cout << output << std::endl;

	}
	return 0;
}