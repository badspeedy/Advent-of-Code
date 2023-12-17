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
	std::string password;

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
		password += hash[5];
	}
	std::cout << password << std::endl;
}
