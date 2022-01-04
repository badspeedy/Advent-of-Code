#include <iostream>

int main() {

	int loop = 1;
	int x_target = 3075, y_target = 2981, x_current = 1, y_current = 1;
	unsigned long long code = 20151125;

	do {

		code = (code * 252533) % 33554393;

		if (x_current < loop) {
			x_current++;
		}
		else {
			loop++;
			x_current = 1;
		}
		y_current = loop - x_current + 1;
    
	} while ((x_target != x_current) || (y_target != y_current));

	std::cout << code << std::endl;

	return 0;
