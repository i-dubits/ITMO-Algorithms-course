// Ilya Dubitskiy
// Week_8_task_2_ver_1


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
#include <list>

#include <unordered_set>
#include <unordered_map>

//#include "edx-io.hpp"



int main()
{
	std::ifstream cin("input.txt");
	std::ofstream cout("output.txt");
	std::cin.rdbuf(cin.rdbuf());
	std::cout.rdbuf(cout.rdbuf());


	std::list<std::string> my_list;
	std::unordered_map<std::string, std::list<std::string>::iterator> my_map;
	
	long oper_numb = 0;

	std::string oper_type;
	std::string curr_key;
	std::string curr_key_value;

	std::string test;

	std::cin >> oper_numb;

	for (long i = 0; i < oper_numb; i++)
	{
		std::cin >> oper_type;

		if (oper_type == "get")
		{
			std::cin >> curr_key;
			auto p1 = my_map.find(curr_key);
			if (p1 == my_map.end())
			{
				std::cout << "<none>\n";
			}
			else
			{
				std::cout << *(p1->second) << "\n";
			}


		}
		else if (oper_type == "prev")
		{
			std::cin >> curr_key;

			auto p1 = my_map.find(curr_key);
			if (p1 == my_map.end())
			{
				std::cout << "<none>\n";
			}
			else
			{
				if (p1->second == my_list.begin())
				{
					std::cout << "<none>\n";
				}
				else
				{
					auto temp = p1->second;
					std::cout << *(--temp) << "\n";
				}
			}
		}
		else if (oper_type == "next")
		{

			std::cin >> curr_key;
			auto p1 = my_map.find(curr_key);

			if (p1 == my_map.end())
			{
				std::cout << "<none>\n";
			}
			else
			{
				auto temp = p1->second;
				if ( (++temp) == my_list.end())
				{
					std::cout << "<none>\n";
				}
				else
				{
					auto temp = p1->second;
					std::cout << *(++temp) << "\n";
				}
			}

		}
		else if (oper_type == "put")
		{
			std::cin >> curr_key;
			std::cin >> curr_key_value;
			
			auto p = my_map.find(curr_key);
			if (p == my_map.end())
			{
				my_list.push_back(curr_key_value);
				my_map.insert({ curr_key, --my_list.end() });
			}
			else
			{
				*(p->second) = curr_key_value;
			}

		}
		else if (oper_type == "delete")
		{
			std::cin >> curr_key;

			auto p = my_map.find(curr_key);
			if (p != my_map.end())
			{
				auto temp = p->second;
				my_map.erase(curr_key);
				my_list.erase(temp);
			}

			
		}

	}

	std::cout << test;

	return 0;

}
