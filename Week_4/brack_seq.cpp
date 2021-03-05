// Ilya Dubitskiy
// Week_4_task_3_ver_1




#include "stdafx.h"
#include <iostream>
#include <fstream>

#include <time.h>


#include <array> 
#include <string>
#include <utility>
#include <stack>

int _tmain(int argc, _TCHAR* argv[])
{

	std::ifstream cin("input.txt");
	std::ofstream cout("output.txt");
	std::cin.rdbuf(cin.rdbuf());
	std::cout.rdbuf(cout.rdbuf());

	clock_t t;
	t = clock();

	std::string curr_seq;


	long number_of_seq = 0;
	char current_br = 0;

	std::cin >> number_of_seq;

	for (long i = 0; i < number_of_seq; i++)
	{
		std::stack<char> all_br;

		int start_sq = 0;
		int start_curr = 0;

		std::cin >> curr_seq;
		
		auto p = curr_seq.begin();

		for ( p = curr_seq.begin(); p != curr_seq.end(); p++)
		{
			if ( *p == '(' || *p == '[')
			{
				all_br.push(*p);
			}
	
			else if ( *p == ')' )
			{
				if (all_br.empty())
				{
					std::cout << "NO\n";
					break;
				}

				current_br = all_br.top();
				if (current_br != '(')
				{
					std::cout << "NO\n";
					break;
				}
				all_br.pop();


			}
			else if ( *p == ']' )
			{
				if (all_br.empty())
				{
					std::cout << "NO\n";
					break;
				}

				current_br = all_br.top();
				if (current_br != '[')
				{
					std::cout << "NO\n";
					break;
				}
				all_br.pop();
			}

		}
		if (p == curr_seq.end() && all_br.empty())
		{
			std::cout << "YES\n";
		}
		else if(p == curr_seq.end() && !all_br.empty())
		{
			std::cout << "NO\n";
		}

				
	}

	return 0;

}
