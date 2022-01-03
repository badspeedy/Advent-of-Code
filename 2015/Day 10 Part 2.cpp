#include <fstream>
#include <iostream>
#include <string>

std::string s_input;
std::string working;

int main() {

	int max_loops = 50;	
	int count = 1;
	int current;
	char temp[2];
	temp[1] = NULL;
	std::cin >> s_input;

	for (int loops = 0; loops < max_loops; loops++) {
		working.erase();
		for (int i = 0; i < s_input.size(); i++) {
			if (s_input[i] == s_input[i + 1]) {
				count++;
			}
			else {
				temp[0] = s_input[i];
				current = std::stoi(temp);
				working.append(std::to_string(count));
				working.append(std::to_string(current));
				count = 1;
			}
		}
		s_input = working;
	}

	std::cout << s_input.size() << std::endl;
	return 0;
}