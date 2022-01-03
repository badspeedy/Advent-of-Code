int main() {

	int find;
	int result;
	int house = 0;
	std::cin >> find;
	uint8_t d[500000] = {0};
	do {
		house++;
		result = 0;
		for (int i = 1; i <= (house/2); i++) {
			if (d[i] < 50) {
				if ((house % i) == 0) {
					result += (i * 11);
					d[i]++;
				}
			}
			else { continue; }
		}
		result += (house * 11);
	} while (result < find);

	std::cout << house << std::endl;

	return 0;
}