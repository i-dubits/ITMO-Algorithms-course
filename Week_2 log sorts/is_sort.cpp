// Ilya Dubitskiy
// Week_2_task_5_ver_1




#include "stdafx.h"
#include <iostream>
#include <fstream>





//#include "edx-io.hpp"


//using namespace std;


class my_array {

public:

	long array_val;
	long id_init;

	
	my_array(long array_val = 0, long id_init = 0);
	my_array& operator= (my_array arg_1);

};

my_array::my_array(long w, long ind) :array_val(w), id_init(ind)
{}

my_array& my_array::operator=(my_array arg_1)
{
	array_val = arg_1.array_val;
	id_init = arg_1.id_init;

	return *this;
}


void swap(my_array& arg_1, my_array& arg_2)
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


long partition_fast(my_array* arr, long low, long high)
{
	long pivot = arr[high].array_val;    // pivot
	long i = (low - 1);  // Index of smaller element

	for (long j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j].array_val <= pivot)
		{
			i++;    // increment index of smaller element
			swap_fast(&arr[i], &arr[j]);
		}
	}
	swap_fast(&arr[i + 1], &arr[high]);
	return (i + 1);
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
				swap(arr[i], arr[j]);
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



my_array* array_gen(long n, long k_1, long k_2, long A, long B, long C, long a_1, long a_2)
{
	my_array* res;
	res = new my_array[n+1];

	res[1].array_val = a_1;
	res[2].array_val = a_2;


	for (long i = 3; i <= n; i++)
	{
		res[i].array_val = A * res[i - 2].array_val + B * res[i - 1].array_val + C;
	}

	return res;

}

long  partition(my_array* arr, long l, long r)
{
	long x = arr[r].array_val, i = l;
	for (long j = l; j <= r - 1; j++) {
		if (arr[j].array_val <= x)
		{
			swap_fast(&arr[i], &arr[j]);
			i++;
		}
	}
	swap_fast(&arr[i], &arr[r]);
	return i;
}


int _tmain(int argc, _TCHAR* argv[])
{

	std::ifstream cin("input.txt");
	std::ofstream cout("output.txt");
	std::cin.rdbuf(cin.rdbuf());
	std::cout.rdbuf(cout.rdbuf());

	my_array* my_struct;
	long n = 0;
	long k = 0;



	std::cin >> n;
	std::cin >> k;


	//my_struct = new my_array[n+1];
	//my_struct_test = new my_array[n];

	my_struct = new my_array[n + 1];

	for (long i = 1; i <= n; i++)
	{
		std::cin >> my_struct[i].array_val;
		my_struct[i].id_init = i;
	}


	quickSort_fast(my_struct, 1, n);

	/*std::cout << "\nAfter sort" << "\n Values\n";
	for (long i = 1; i <= n; i++)
	{
		std::cout << my_struct[i].array_val << " ";
	}
	std::cout << "\nAfter sort" << "\n Indices\n";
	for (long i = 1; i <= n; i++)
	{
		std::cout << my_struct[i].id_init << " ";
	}*/

	int answer = 0;
	long i_global = 1;
	while (i_global <= n)
	{
		long i_local = i_global;
		while (my_struct[i_local].array_val == my_struct[i_local + 1].array_val && i_local + 1 <= n)
		{
			i_local++;
		}
		if (i_local != i_global)
		{
			for (long i = i_global; i <= i_local; i++)
			{
		
					for (long j = i_global; j <= i_local; j++)
					{
						if ((i - my_struct[j].id_init) % k == 0)
						{
							answer = 1;
							break;
						}
						else
						{
							answer = 0;
						}
					}

					if (answer == 1)
					{
						break;
					}

			}
			if (answer == 0)
			{
				std::cout << "NO\n";
				exit(0);
			}
			else
			{
				i_global = i_local + 1;
			}
			
		}
		else if((i_global - my_struct[i_global].id_init) % k != 0)
		{
			std::cout << "NO\n";
			exit(0);
		}
		else if ((i_global - my_struct[i_global].id_init) % k == 0)
		{
			i_global++;
		}

	}

	if (i_global == n + 1)
	{
		std::cout << "YES\n";
	}

	/*std:cout << "Value\n";
	for (long i = 1; i <= n; i++)
	{
		std::cout << my_struct[i].array_val << " ";
	}

	std::cout << "Init id\n";
	for (long i = 1; i <= n; i++)
	{
		std::cout << my_struct[i].id_init << " ";
	}*/

	/*my_array my_test_1(2324, 1);
	my_array my_test_2(1000, 2);

	std::cout << "\nNew val " << my_test_2.array_val << " New id " << my_test_2.id_init;
	//my_test_2 = my_test_1;
	swap(my_test_2, my_test_1);
	std::cout << "\nNew val " << my_test_2.array_val << " New id " << my_test_2.id_init;
	*/

	
	//cout << "\n";
	//system ("pause");
	return 0;
}
