#include <fstream>
#include <iostream>
#include <string>


std::string s_input;

struct prog
{
	std::string cmd;
	std::string reg;
	int offset;
};

enum cmd {
hlf,
tpl,
inc,
jmp,
jie,
jio,
areg,
breg,
end
};

cmd hashit(std::string const& inString) {
	if (inString == "hlf") return hlf;
	if (inString == "tpl") return tpl;
	if (inString == "inc") return inc;
	if (inString == "jmp") return jmp;
	if (inString == "jie") return jie;
	if (inString == "jio") return jio;
	if (inString == "a") return areg;
	if (inString == "b") return breg;
	if (inString == "end") return end;
}

int main() {
	prog main[50];
	int line = 0;
	std::ifstream file("Day 23.txt");

	while (file.is_open()) {
		while (std::getline(file, s_input)) {
			main[line].cmd = s_input.substr(0, 3);
			if (main[line].cmd == "jmp") {
				main[line].offset = std::stoi(s_input.substr(4, s_input.size() - 4));
			}
			else {
				if (main[line].cmd == "jie" || main[line].cmd == "jio") {
					main[line].reg = s_input.substr(4, 1);
					main[line].offset = std::stoi(s_input.substr(6, s_input.size() - 6));

				}
				else {
					main[line].reg = s_input.substr(4, s_input.size() - 4);
				}

			}
			line++;
		}

		file.close();
		main[line].cmd = "end";
	}

	unsigned long long a = 0, b = 0, pc = 0;

	while (1) {
		switch (hashit(main[pc].cmd))
		{
		case hlf:
			if (hashit(main[pc].reg) == areg) {
				a /= 2;
			}
			else {
				b /= 2;
			}
			pc++;
			break;

		case tpl:
			if (hashit(main[pc].reg) == areg) {
				a *= 3;
			}
			else {
				b *= 3;
			}
			pc++;
			break;

		case inc:
			if (hashit(main[pc].reg) == areg) {
				a++;
			}
			else {
				b++;
			}
			pc++;
			break;

		case jmp:
			pc += main[pc].offset;
			break;

		case jie:
			if (hashit(main[pc].reg) == areg) {
				if (a % 2 == 0) {
					pc += main[pc].offset;
				}
				else {
					pc++;
				}
			}
			else {
				if (b % 2 == 0) {
					pc += main[pc].offset;
				}
				else {
					pc++;
				}
			}
			break;

		case jio:
			if (hashit(main[pc].reg) == areg) {
				if (a  == 1) {
					pc += main[pc].offset;
				}
				else {
					pc++;
				}
			}
			else {
				if (b == 1) {
					pc += main[pc].offset;
				}
				else {
					pc++;
				}
			}
			break;

		case end:
				std::cout << b << std::endl;
				while (1);
				break;

		default:
			break;
		}
	}

	return 0;
}
