#include <fstream>
#include <iostream>
#include <string>

std::string s_input;

std::string next(std::string a) {
	int i = a.size();

	do {
		if (a[i - 1] == 'z') {
			a[i - 1] = 'a';
			i--;
		}
		else {
			a[i - 1]++;
			i = 0;
		}
	} while (i > 0);
	return a;
}

bool test1(std::string a) {
	for (int j = 0; j < (a.size() - 2); j++) {
		if ((a[j] == (a[j + 1] - 1)) && ((a[j + 1]) == (a[j + 2] - 1))) {
			return true;
		}
	}
	return false;
}

bool test2(std::string a) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 'i' || a[i] == 'o' || a[i] == 'l') {
			return false;
		}
	}
	return true;
}

bool test3(std::string a) {
	bool set1 = 0;
	for (int i = 0; i < (a.size() - 1); i++) {
		if (a[i] == a[i + 1] && set1 == 0) {
			i++;
			set1 = 1;
		}
		else if (a[i] == a[i + 1] && set1 == 1) {
			return true;
		}
	}
	return false;
}

int main() {

	std::cin >> s_input;

	do {
		s_input = next(s_input);
	} while (test1(s_input) != true || test2(s_input) != true || test3(s_input) != true);


	std::cout << s_input << std::endl;

	return 0;
}