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

//#include "edx-io.hpp"


//using namespace std;


class my_array {

public:

	long array_val;
	//long id_init;

	
	my_array(long array_val = 0);
	my_array& operator= (my_array arg_1);

};

my_array::my_array(long w) :array_val(w)
{}

my_array& my_array::operator=(my_array arg_1)
{
	array_val = arg_1.array_val;
	//id_init = arg_1.id_init;

	return *this;
}


void swap_1(my_array& arg_1, my_array& arg_2)
{
	my_array temp = arg_1;
	arg_1 = arg_2;
	arg_2 = temp;
}

void swap_fast(my_array* a, my_array* b)
{
	my_array t = *a;
	*a = *b;
	*b = t;
}

// true if first arg lesser than second arg
bool if_less(my_array arg_1, my_array arg_2)
{
	return arg_1.array_val <= arg_2.array_val;
}

inline bool operator>(const my_array& lhs, const my_array& rhs)
{
	return rhs.array_val < lhs.array_val;
}

inline bool operator<(const my_array& lhs, const my_array& rhs)
{
	return rhs.array_val > lhs.array_val;
}


void quickSort_fast(my_array* arr, long low, long high)
{
start:
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		long i = low;
		long j = high;
		long pivot = arr[(low + high) / 2].array_val;

		while (i <= j)
		{

			while (arr[i].array_val < pivot)
				i++;

			while (arr[j].array_val > pivot)
				j--;

			if (i <= j)
			{
				swap_1(arr[i], arr[j]);
				i++;
				j--;
			}

		}

		// Separately sort elements before
		// partition and after partition
		quickSort_fast(arr, low, j);

		low = i;
		high = high;
		goto start;
	}
}


// A utility function to get maximum value in arr[]
long getMax(my_array* arr, long n_dot_m)
{
	long mx = arr[0].array_val;
	for (int i = 1; i < n_dot_m; i++)
		if (arr[i] > mx)
			mx = arr[i].array_val;
	return mx;
}

 
void countSort(my_array* arr, long n_dot_m, long exp, long base)
{
	//int output[n]; 
	long i = 0;
	my_array* output_array = new my_array[n_dot_m];
	my_array* count = new my_array[base];

	// Store count of occurrences in count[] 
	for (i = 0; i < n_dot_m; i++)
		count[ (arr[i].array_val / exp) % base].array_val++;

	// Change count[i] so that count[i] now contains actual 
	//  position of this digit in output[] 
	for (i = 1; i < base; i++)
		count[i].array_val += count[i - 1].array_val;

	// Build the output array 
	for (i = n_dot_m - 1; i >= 0; i--)
	{
		output_array[count[(arr[i].array_val / exp) % base].array_val - 1].array_val = arr[i].array_val;
		count[(arr[i].array_val / exp) % base].array_val--;
	}

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < n_dot_m; i++)
		arr[i] = output_array[i];
	
	delete[] output_array;
	delete[] count;
}

// The main function to that sorts arr[] of size n using  
// Radix Sort 
void radixsort(my_array* arr, long n_dot_m, long base)
{
	// Find the maximum number to know number of digits 
	long m = getMax(arr, n_dot_m);

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (long exp = 1; m / exp > 0; exp *= base)
		countSort(arr, n_dot_m, exp, base);
}

void exch_strings_except_one_rad(std::string* string_radix_list, long first_str_numb, long sec_str_numb, long except_rad, long str_length)
{
	long curr_rad = 0;

	while (curr_rad < str_length)
	{
		if (curr_rad == except_rad)
		{
			curr_rad++;
		}
		else
		{
			char tmp_char = string_radix_list[curr_rad][first_str_numb];
			string_radix_list[curr_rad][first_str_numb] = string_radix_list[curr_rad][sec_str_numb];
			string_radix_list[curr_rad][sec_str_numb] = tmp_char;
			curr_rad++;
		}
	}
}



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