// Ilya Dubitskiy
// Week_6_task_1_ver_1




#include "stdafx.h"
#include <iostream>
#include <fstream>

#include <time.h>



#include <string>
#include <vector>
#include <limits>



//#include "edx-io.hpp"


long left(long* my_arr, long arr_size, long val)
{
	long left = 0;
	long right = arr_size;
	long mid = 0;


	while (left < right)
	{
		mid = (left + right) / 2;
		
		if ( my_arr[mid] < val )
		{
			left = mid + 1;
		}
		else if( my_arr[mid] >= val )
		{
			right = mid;
		}		
	}

	if (my_arr[left] == val)
	{
		return left;
	}
	else
	{
		return -2;
	}
}

long right(long* my_arr, long arr_size, long val)
{
	long left = 0;
	long right = arr_size;
	long mid = 0;


	while (left < right)
	{
		mid = (left + right) / 2;

		if (my_arr[mid] <= val)
		{
			left = mid + 1;
		}
		else if (my_arr[mid] > val)
		{
			right = mid;
		}
	}

	if (my_arr[right - 1] == val)
	{
		return right - 1;
	}
	else
	{
		return -2;
	}
}




int _tmain(int argc, _TCHAR* argv[])
{

	std::ifstream cin("input.txt");
	std::ofstream cout("output.txt");
	std::cin.rdbuf(cin.rdbuf());
	std::cout.rdbuf(cout.rdbuf());

	//clock_t t;
	//t = clock();

	long arr_size = 0;
	long oper_numb = 0;
	long curr_val = -1;
	

	
	std::cin >> arr_size;
	long* my_arr = new long[arr_size];

	for (long i = 0; i < arr_size; i++)
	{
		std::cin >> my_arr[i];
	}
	std::cin >> oper_numb;

	while (oper_numb != 0)
	{
		std::cin >> curr_val;

	std:cout << left(my_arr, arr_size, curr_val) + 1 << " " << right(my_arr,  arr_size, curr_val) + 1 << "\n";


		oper_numb--;
	}




	return 0;

}
