// Ilya D
// Week_2_task_1_ver_1




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

my_array::my_array(long w, long id_in) :array_val(w), id_init(id_in)
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

// true if first arg lesser than second arg
bool if_less(my_array arg_1, my_array arg_2)
{
	return arg_1.array_val <= arg_2.array_val;
}


// Merge two subsequent parts of the same array
long long  merge_arrays(my_array* init_array, long first_el_first_array, long last_el_first_array, long last_el_last_array)
{
	my_array* aux_array = new my_array[last_el_last_array - first_el_first_array + 1];
	long inv_number = 0;

	for (long i = 0; i < last_el_last_array - first_el_first_array + 1; i++)
	{
		aux_array[i] = init_array[first_el_first_array + i];
	}

	long i = 0;
	long j = last_el_first_array + 1 - first_el_first_array;
	long k = 0;

	for (long i1 = 0; i1 < last_el_last_array - first_el_first_array + 1; i1++)
	{
		if (i < last_el_first_array - first_el_first_array + 1 && j < last_el_last_array - first_el_first_array + 1)
		{
			if (if_less(aux_array[i], aux_array[j]))
			{
				init_array[first_el_first_array + k] = aux_array[i];
				i++;
				k++;
			}
			else
			{
				init_array[first_el_first_array + k] = aux_array[j];
				j++;
				k++;
				inv_number+= last_el_first_array - first_el_first_array + 1 - i;
			}
		}
		else if (j >= last_el_last_array + 1 - first_el_first_array)
		{
			init_array[first_el_first_array + k] = aux_array[i];
			i++;
			k++;
		}
		else if (i >= last_el_first_array + 1 - first_el_first_array)
		{
			init_array[first_el_first_array + k] = aux_array[j];
			j++;
			k++;
		}

	}

	return inv_number;

	
}


int _tmain(int argc, _TCHAR* argv[])
{

	std::ifstream cin("input.txt");
	std::ofstream cout("output.txt");
	std::cin.rdbuf(cin.rdbuf());
	std::cout.rdbuf(cout.rdbuf());

	long  n = 0;
	long long inv_number = 0;
	
	std::cin >> n;

	my_array* my_struct;
		
	my_struct = new my_array[n];
	
	

	for (long i = 0; i < n; i++)
	{
		std::cin >> my_struct[i].array_val;
		my_struct[i].id_init = i;
	}
	


	for (long i = 1; i < n; i+=i)
	{

		for (long sz = 0; sz < n - i; sz += i+i)
		{
			if (sz + i + i < n)
			{
				inv_number += merge_arrays(my_struct, sz, sz + i - 1, sz + i + i - 1);
			}
			else
			{
				inv_number += merge_arrays(my_struct, sz, sz + i - 1, n-1);
			}
		}


	}

	std::cout << inv_number;





	delete[] my_struct;
	
	//cout << "\n";
	//system ("pause");
	return 0;
}
