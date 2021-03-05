// Ilya Dubitskiy
// Week_2_task_3_ver_2




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

my_array::my_array(long w, long id) :array_val(w), id_init(id)
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

long comp_number = 0;
void quickSort(my_array* arr, long low, long high)
{

		/* pi is partitioning index, arr[p] is now
		   at right place */
		long i = low;
		long j = high;
		long pivot = arr[(low + high) / 2].array_val;

		while (i <= j)
		{

			while (arr[i].array_val < pivot)
			{
				i++;
				comp_number++;
			}
			comp_number++;

			while (arr[j].array_val > pivot)
			{
				j--;
				comp_number++;
			}
			comp_number++;

			if (i <= j)
			{
				swap(arr[i], arr[j]);
				i++;
				j--;
			}

		}

		// Separately sort elements before
		// partition and after partition
		if (low < j)
		quickSort(arr, low, j);

		if (i < high)
		quickSort(arr, i, high);

		
	
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
			{
				//comp_number++;
				i++;
			}

			while (arr[j].array_val > pivot)
			{
				j--;
				//comp_number++;
			}
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

	my_array* my_struct_current;
	my_array* my_struct_current_max;
	long curr_comp_max = -1;



	std::cin >> n;

	my_struct = new my_array[n + 1];
	my_struct_current = new my_array[n + 1];
	my_struct_current_max = new my_array[n + 1];

	for (long i = 1; i < n + 1; i++)
	{
		my_struct[i].array_val = i;
		my_struct[i].id_init = i;

		my_struct_current[i].array_val = i;
		my_struct_current[i].id_init = i;
	}

	for (long i = 1; i <= n; i++)
	{
		swap(my_struct[i], my_struct[(i + 1) / 2]);
		swap(my_struct_current[i], my_struct_current[(i + 1) / 2]);
	}

	long index_1 = -1;
	long index_3 = -1;
	long my_index = 1;
	
	if (n >=3)
	{
		while (my_index <= n)
		{
			if (my_struct[my_index].id_init == 1)
			{
				index_1 = my_index;
			}
			if (my_struct[my_index].id_init == 3)
			{
				index_3 = my_index;
			}
			if (index_3 != -1 && index_1 != -1)
			{
				break;
			}
			my_index++;
		}
		swap(my_struct[index_1], my_struct[index_3]);
	}

	if (n == 2)
	{
		int one = 1;
		int two = 2;
		std::cout << one << " " << two;
		exit(0);
	}

	


	for (long i = 1; i < n + 1; i++)
	{
		std::cout << my_struct[i].array_val << " ";
	}

	int index = 1;



/*	while (index <= n)
	{
		comp_number = 0;
		quickSort(my_struct, 1, n);

		if (curr_comp_max < comp_number)
		{
			curr_comp_max = comp_number;
			for (long i = 1; i < n + 1; i++)
			{
				my_struct_current_max[i] = my_struct_current[i];
			}
		}
		
		if (index == 1 && index != n)
		{
			swap(my_struct_current[index], my_struct_current[index + 1]);

		}
		else if(index != 1 && index != n)
		{
			swap(my_struct_current[index - 1], my_struct_current[index]);
			swap(my_struct_current[index], my_struct_current[index + 1]);

		}
		if (index == n)
		{
			break;
		}
		for (long i = 1; i < n + 1; i++)
		{
			my_struct[i] = my_struct_current[i];
		}

		index++;
	}
*/	
	
	std::cout << "\nNumb of comp " << comp_number;

	std::cout << "\nRes array\n ";
	for (long i = 1; i < n + 1; i++)
	{
		std::cout << my_struct_current_max[i].array_val << " ";
	}
	
	//cout << "\n";
	//system ("pause");
	return 0;
}
