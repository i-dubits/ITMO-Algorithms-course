// Ilya Dubitskiy
// Week_3_task_1_ver_4




#include "stdafx.h"
#include <iostream>
#include <fstream>

#include <time.h>


#include  <algorithm>

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




//  a is input array, b is working array
my_array* RadixSort(my_array* a, my_array* b, long count)
{
	long mIndex[4][256] = { 0 };           
	long i, j, m, n;
	long u;
	for (i = 0; i < count; i++) {         
		u = a[i].array_val;
		for (j = 0; j < 4; j++) {
			mIndex[j][(size_t)(u & 0xff)]++;
			u >>= 8;
		}
	}
	for (j = 0; j < 4; j++) {             
		m = 0;
		for (i = 0; i < 256; i++) {
			n = mIndex[j][i];
			mIndex[j][i] = m;
			m += n;
		}
	}
	for (j = 0; j < 4; j++) {             
		for (i = 0; i < count; i++) {     
			u = a[i].array_val;
			m = (size_t)(u >> (j << 3)) & 0xff;
			b[mIndex[j][m]++] = u;
		}
		std::swap(a, b);                
	}
	return(a);
}



int _tmain(int argc, _TCHAR* argv[])
{

	std::ifstream cin("input.txt");
	std::ofstream cout("output.txt");
	std::cin.rdbuf(cin.rdbuf());
	std::cout.rdbuf(cout.rdbuf());

	clock_t t;
	t = clock();

	my_array* my_struct_n;
	my_array* my_struct_m;
	my_array* my_struct_n_dot_m;
	my_array* my_struct_n_dot_m_aux;
	
	long n = 0;
	long m = 0;
	long res = 0;

	std::cin >> n >> m;
	my_struct_n = new my_array[n];
	my_struct_m = new my_array[m];
	my_struct_n_dot_m = new my_array[n*m];
	my_struct_n_dot_m_aux = new my_array[n * m];

	t = clock() - t;
	
	for (long i = 0; i < n; i++)
	{
		std::cin >> my_struct_n[i].array_val;
		//my_struct_n[i].array_val = i+1;
		//my_struct_n[i].id_init = i;
	}
	t = clock() - t;
	std::cout << "\nTime init  el: " << ((float)t) / CLOCKS_PER_SEC;
	for (long i = 0; i < m; i++)
	{
		std::cin >> my_struct_m[i].array_val;
		//my_struct_m[i].array_val = i+1;
		//my_struct_m[i].id_init = i;
	}

	t = clock() - t;


	long k = 0;
	for (long i = 0; i < n; i++)
	{
		for (long j = 0; j < m; j++)
		{
			my_struct_n_dot_m[k].array_val = my_struct_n[i].array_val * my_struct_m[j].array_val;
			k++;
			//my_struct_m[i].array_val = i;
			//my_struct_m[i].id_init = i;
		}
	}
	t = clock() - t;
	std::cout << "\nTime product calc: " << ((float)t) / CLOCKS_PER_SEC;
	//std::cout << "\n";
	long long final_sum = 0;
	
	my_struct_n_dot_m = RadixSort(my_struct_n_dot_m, my_struct_n_dot_m_aux, n*m);
	t = clock() - t;
	std::cout << "\nTime radix sort el: " << ((float)t) / CLOCKS_PER_SEC;

	std::cout << "\n";
	t = clock() - t;
	for (long i = 0; i < n * m; i+=10)
	{
		final_sum += my_struct_n_dot_m[i].array_val;
		std::cout << my_struct_n_dot_m[i].array_val << " ";
	}
	t = clock() - t;
	std::cout << "\nFinal res calc: " << ((float)t) / CLOCKS_PER_SEC;


	std::cout << "\n" <<  final_sum;

	


	return 0;
}