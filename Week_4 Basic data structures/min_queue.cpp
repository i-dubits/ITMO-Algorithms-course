// Ilya Dubitskiy
// Week_4_task_4_ver_1




#include "stdafx.h"
#include <iostream>
#include <fstream>

#include <time.h>


#include <array> 
#include <string>
#include <utility>
#include <stack>

//#include "edx-io.hpp"


//using namespace std;


long min(std::stack<std::pair<long, long>>& s1, std::stack<std::pair<long, long>>& s2)
{
	long minimum = 0;

	if (s1.empty() || s2.empty())
		 minimum = s1.empty() ? s2.top().second : s1.top().second;
	else
		 minimum = std::min(s1.top().second, s2.top().second);

	return minimum;
}

void push_el(std::stack<std::pair<long, long>>& s1, long new_element)
{
	long minimum = s1.empty() ? new_element : std::min(new_element, s1.top().second);
	s1.push({ new_element, minimum });
}

void pop_el(std::stack<std::pair<long, long>>& s1, std::stack<std::pair<long, long>>& s2)
{
	if (s2.empty()) {
		while (!s1.empty()) {
			long element = s1.top().first;
			s1.pop();
			long minimum = s2.empty() ? element : std::min(element, s2.top().second);
			s2.push({ element, minimum });
		}
	}
	long remove_element = s2.top().first;
	s2.pop();
}



int _tmain(int argc, _TCHAR* argv[])
{

	std::ifstream cin("input.txt");
	std::ofstream cout("output.txt");
	std::cin.rdbuf(cin.rdbuf());
	std::cout.rdbuf(cout.rdbuf());

	clock_t t;
	t = clock();

	long number_of_oper = 0;
	std::cin >> number_of_oper;

	std::stack<std::pair<long, long>> s1, s2;
	std::string curr_str;

	char curr_oper = 0;
	long curr_number = 0;

	while (number_of_oper > 0)
	{
		std::cin >> curr_oper;

		if (curr_oper == '+')
		{
			std::cin >> curr_number;
			push_el(s1, curr_number);
		}
		else if (curr_oper == '-')
		{
			pop_el(s1, s2);
		}
		else if (curr_oper == '?')
		{
			std::cout << min(s1, s2) << "\n";
		}
		number_of_oper--;
	}

		

	return 0;

}
