// Ilya Dubitskiy


//#include "edx-io.hpp"

#include "stdafx.h"

#include <iostream>
#include <fstream>

#include <stack> 


int main()
{
	std::ifstream cin("input.txt");
	std::ofstream cout("output.txt");
	std::cin.rdbuf(cin.rdbuf());
	std::cout.rdbuf(cout.rdbuf());

	std::stack<long> my_stack;

	long numb_oper = 0;
	char curr_char = 0;

	std::cin >> numb_oper;

	long first = 0;
	long second = 0;

	for (long i = 0; i < numb_oper; i++)
	{
		std::cin >> curr_char;

		if (curr_char != '+' && curr_char != '*' && curr_char != '-')
		{
			my_stack.push(curr_char - 48);
		}
		else if (curr_char == '+')
		{
			first = my_stack.top();
			my_stack.pop();

			second = my_stack.top();
			my_stack.pop();

			my_stack.push(first + second);
		}
		else if (curr_char == '-')
		{
			first = my_stack.top();
			my_stack.pop();

			second = my_stack.top();
			my_stack.pop();

			my_stack.push(second - first);
		}
		else if (curr_char == '*')
		{
			first = my_stack.top();
			my_stack.pop();

			second = my_stack.top();
			my_stack.pop();

			my_stack.push(second * first);
		}
	}

	std::cout << my_stack.top();

	return 0;

}
