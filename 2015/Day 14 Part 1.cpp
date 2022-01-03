#include <fstream>
#include <iostream>
#include <string>

std::string s_input;

int main() {

	struct raindear
	{
		int speed, worktime, resttime, temp;
		bool rest;
		int total;
		int star;
	};
	raindear a[9];



	std::ifstream file("Day 14.txt");

	while (file.is_open()) {
		int b = 0;
		while (std::getline(file, s_input)) {
			a[b].speed = std::stoi(s_input.substr((s_input.find("km\0") - 3), 2));
			a[b].worktime = std::stoi(s_input.substr((s_input.find("seconds,\0") - 3), 2));
			a[b].resttime = std::stoi(s_input.substr((s_input.find("seconds.\0") - 4), 3));
			b++;
		}

		file.close();
	}
	
	for (int i = 0; i < 9; i++) {
		a[i].rest = false;
		a[i].total = 0;
		a[i].temp = a[i].worktime;
		a[i].star = 0;
	}

	int duration = 2503;
	int high;

	for (int i = 0; i < duration; i++) {
		high = 0;
		for (int j = 0; j < 9;j++) {
			if (a[j].rest == true) {
				if (a[j].temp > 1) {
					a[j].temp--;
					continue;
				}
				a[j].rest = false;
				a[j].temp = a[j].worktime;
				continue;
			}
			else {
				if (a[j].temp > 1) {
					a[j].temp--;
					a[j].total += a[j].speed;
					continue;
				}
				a[j].total += a[j].speed;
				a[j].rest = true;
				a[j].temp = a[j].resttime;
				continue;
			}
		}
		for (int j = 0; j < 9; j++) {
			if (a[j].total > high) {
				 high = a[j].total;
			}
		}
		for (int j = 0; j < 9; j++) {
			if (a[j].total == high) {
				a[j].star++;
			}
		}

	}


	for (int i = 0; i < 9; i++) {

		std::cout << a[i].total << std::endl;
	}

	return 0;