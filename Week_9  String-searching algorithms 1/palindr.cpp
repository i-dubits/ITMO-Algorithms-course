// Ilya Dubitskiy
// Week_9_task_1_ver_1


#include "stdafx.h"
#include <iostream>
#include <fstream>

#include <time.h>
#include <cmath>

#include <iomanip>


#include <string>
#include <vector>
#include <limits>
#include <queue>
#include <stack>
#include <algorithm>

#include <unordered_set>

long brut_force(std::string string, std::string substring, std::vector<long>& numbers)
{
	long str_length = string.length();
	long substr_length = substring.length();
	long count = 0;

	for (long i = 0; i <= str_length - substr_length; i++)
	{
		long j = 0;
		for (j = 0; j < substr_length; j++)
		{
			if (string[i + j] != substring[j])
			{
				break;
			}
		}
		if (j == substr_length)
		{
			numbers.push_back(i + 1);
			count++;
		}
	}

	return count;
}

long brut_force_2(std::string string, std::string substring)
{
	long str_length = string.length();
	long substr_length = substring.length();
	long count = 0;

	for (long i = 0; i <= str_length - substr_length; i++)
	{
		long j = 0;
		for (j = 0; j < substr_length; j++)
		{
			if (string[i + j] != substring[j])
			{
				break;
			}
		}
		if (j == substr_length)
		{
			return i;
		}
	}

	return -1;
}


int main()
{
	std::ifstream cin("input.txt");
	std::ofstream cout("output.txt");
	std::cin.rdbuf(cin.rdbuf());
	std::cout.rdbuf(cout.rdbuf());

	std::string string;

	
	std::getline(std::cin, string);
	//std::cin >> string;

	std::string::iterator end_pos = std::remove(string.begin(), string.end(), ' ');
	string.erase(end_pos, string.end());

	long str_length = string.length();

	long answer = 0;
	for (long i = 0; i < str_length; i++)
	{
		long first_colision = brut_force_2(string.substr(i + 1), string.substr(i, 1));
		long second_colision = brut_force_2(string.substr(first_colision + 1), string.substr(i, 1));
		
		if (first_colision != -1 && second_colision != -1)
		{
			answer = answer + first_colision + 1;
		}
		else if (first_colision != -1 && second_colision == -1)
		{
			answer += answer;
		}
	}

	std::cout << answer;

	return 0;

}
