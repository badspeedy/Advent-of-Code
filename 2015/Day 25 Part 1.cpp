#include <iostream>

int main() {

	int x_target = 3075, y_target = 2981;	//Target code location

	int x_current = 6, y_current = 6;		//Current code location
	unsigned long long code = 27995004;		//Current Code

	int loop = x_current + y_current - 1;

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
