#include <iostream>
#include <string>
#include <fstream>
#include "md5.h"

std::string door_id;
MD5 md5;

int main()
{
	std::cin >> door_id;
	long idx = 0;
	std::string password = "12345678";
	bool got[8] = { 0,0,0,0,0,0,0,0 };

	for (int k = 0; k < 8; k++)
	{
		std::string to_hash;
		std::string hash;
		do
		{
			to_hash = door_id + std::to_string(idx);
			idx++;
			hash = md5(to_hash);

		} while (!(hash.starts_with("00000")));
		char locate_str = hash[5];
		int location = locate_str - '0';
		if (location <= 7) {
			if (!got[location])
			{
				password[location] = hash[6];
				got[location] = 1;
			}
			else
			{
				k--;
			}
		}
		else
		{
			k--;
		}
	}
	std::cout << password << std::endl;
}
