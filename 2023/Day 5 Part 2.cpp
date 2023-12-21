#include <iostream>
#include <string>
#include <fstream>

struct race {
	long long time;
	long long dist;
	long long wins;
};

race races[4] = { {50748685,242101716911252,0},{74,1017,0},{86,1691,0},{85,1252,0} };

int main()
{
	for (int j = 0; j < 1; j++)
	{
		for (long long k = 0; k < races[j].time; k++)
		{
			long long speed = k;
			long long trav = speed * (races[j].time - k);
			if (trav > races[j].dist) 
			{
				races[j].wins++;
			}
		}
	}
	std::cout << (races[0].wins );
}
