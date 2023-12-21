#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

char map[2][131][131];

int main()
{
	std::ifstream file("map.txt");
	int j = 0;
	while (file.is_open()) {
		std::string s_input;
		while (std::getline(file, s_input)) {
			for (int i = 0; i < s_input.size(); i++)
			{
				map[0][i][j] = s_input[i];
				map[1][i][j] = s_input[i];
			}
			j++;
		}

		file.close();
	};
	int loops;
	std::cin >> loops;
	for (int k = 0; k < loops; k++)
	{
		for (int y = 0; y < 131 ; y++)
		{
			for (int x = 0; x < 131; x++)
			{
				if (map[0][x][y] == 'O')
				{
					if (map[0][x][y - 1] == '.')
					{
						map[1][x][y - 1] = 'O';
					}
					if (map[0][x][y + 1] == '.')
					{
						map[1][x][y + 1] = 'O';
					}
					if (map[0][x - 1][y] == '.')
					{
						map[1][x - 1][y] = 'O';
					}
					if (map[0][x + 1][y] == '.')
					{
						map[1][x + 1][y] = 'O';
					}
					map[1][x][y] = '.';
				}
			}
		}
		for (int y = 0; y < 131; y++)
		{
			for (int x = 0; x < 131; x++)
			{
				map[0][x][y] = map[1][x][y];
			}
		}
	}
	int total = 0;
	for (int y = 0; y < 131; y++)
	{
		for (int x = 0; x < 131; x++)
		{
			if (map[0][x][y] == 'O')
			{
				total++;
			}
		}
	}
	std::cout << total;
}
