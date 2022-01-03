#include <fstream>
#include <iostream>
#include <string>

int main() {

	int find;
	int result;
	int house = 0;
	std::cin >> find;

	do {
		house++;
		result = 0;
		for (int i = 1; i <= (house/2); i++) {
				if ((house % i) == 0) {
					result += (i * 10);
				}
		}
		result += (house * 10);
	} while (result <= find);

	std::cout << house << std::endl;

	return 0;
}