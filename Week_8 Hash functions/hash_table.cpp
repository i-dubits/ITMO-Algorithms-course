// Ilya Dubitskiy
// Week_8_task_3_ver_4


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

#include <unordered_set>

long count_X_iter = 0;

const unsigned long long array_size = 16777216; //2^24
const unsigned long long array_size_minus_1 = 16777215; //2^24-1

unsigned long long fast_mod(const unsigned  long long input, const unsigned  long long ceil) {
	// apply the modulo operator only when needed
	// (i.e. when the input is greater than the ceiling)
	return input >= ceil ? input % ceil : input;
	// NB: the assumption here is that the numbers are positive
}

unsigned long long  my_hash_another(unsigned long long x)
{
	x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
	x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
	x = x ^ (x >> 31);
	return x;
}

unsigned long long  my_hash_mult(unsigned long long x)
{
	x ^= x >> (64 - 24);
	return (0x9e3779b97f4a7c15 * x) >> (64 - 24);
}

unsigned long long  my_hash_mult_ver_2(unsigned long long x)
{
	//unsigned long long x1 = x;
	x ^= x >> (50 - 24);
	return (11400714819323198485llu * x) >> (50 - 24);
}

unsigned long long  my_hash_murmash(unsigned long long i)
{
	i += 1ULL;
	i ^= i >> 33ULL;
	i *= 0xff51afd7ed558ccdULL;
	i ^= i >> 33ULL;
	i *= 0xc4ceb9fe1a85ec53ULL;
	i ^= i >> 33ULL;
	return i;
}



unsigned long long  my_hash_mult_2(unsigned long long x)
{
	x ^= x >> (64 - 24);
	return (0x9e3779b97f4a7c15 * x) >> (64 - 24);
}


long long my_hash_func_1(long long key)
{
	return key % 100000000003;
}

long long my_hash_func_2(long long key, long long B)
{
	if (B > 1000)
	{
		return key % B;
	}
	else
	{
		return key % 1000003;
	}
}

unsigned long long my_hash_func(unsigned long long key, long long cell_numb, long long B)
{
	return fast_mod(my_hash_mult(key) + cell_numb * my_hash_mult_2(key), array_size);
}

unsigned long long my_hash_func_mult_2_murmash(unsigned long long key, long long cell_numb)
{
	return fast_mod(my_hash_mult_2(key) + cell_numb * my_hash_murmash(key), array_size);
}

unsigned long long my_hash_func_mult_2_murmash_bitwise(unsigned long long key, long long cell_numb)
{
	unsigned long long mult = my_hash_mult_2(key) & 16777215;
	unsigned long long murmash = my_hash_murmash(key) & 16777215;
	unsigned long long res = (mult + cell_numb * murmash) & 16777215;
	return res;
	//return ( my_hash_mult_2(key) + cell_numb * my_hash_murmash(key) ) & 16777215;
}

unsigned long long my_hash_func_sq(unsigned long long key, unsigned long long cell_numb, long long B)
{
	return (my_hash_another(key) + cell_numb * 10103 + cell_numb * cell_numb * 100183) % array_size;
}

unsigned long long my_hash_func_lin(unsigned long long key, unsigned long long cell_numb, unsigned long long B)
{
	return fast_mod((my_hash_mult(key) + cell_numb), array_size);
}

void put(unsigned long long key, std::vector<long long>& my_hash)
{
	long long i = 0;

	while (i < array_size)
	{
		 long  long j = long long(my_hash_func_mult_2_murmash_bitwise(key, i));
		 //std::cout << "Hash: " << j << "\n";

		if (my_hash[j] == -1)
		{
			my_hash[j] = long long(key);
			break;
		}
		else
		{
			i++;
		}
	}
	if (i > 3)
	{
		std::cout << "i put: " << i << "\n";
	}
}

long long search(unsigned long long key, std::vector<long long>& my_hash)
{
	long long i = 0;
	long long j = long long(my_hash_func_mult_2_murmash_bitwise(key, i));

	while (i < array_size && my_hash[j] != -1)
	{

		if (my_hash[j] == long long (key))
		{
			if (i > 3)
			{
				std::cout << "i search success: " << i << "\n";
			}
			return 1;
		}
		else
		{
			i++;
			j = long long(my_hash_func_mult_2_murmash_bitwise(key, i));
		}


	}
	if (i > 3)
	{
		std::cout << "i search failed: " << i << "\n";
	}

	return -1;
}




int main()
{
	std::ifstream cin("input.txt");
	std::ofstream cout("output.txt");
	std::cin.rdbuf(cin.rdbuf());
	std::cout.rdbuf(cout.rdbuf());

	//std::unordered_set <long long> my_set;
	
	long long N = 0;
	long long X = 0;
	long long A = 0;
	long long B = 0;

	long long A_C = 0;
	long long B_C = 0;
	long long A_D = 0;
	long long B_D = 0;

	std::cin >> N;
	std::cin >> X;
	std::cin >> A;
	std::cin >> B;

	std::cin >> A_C;
	std::cin >> B_C;
	std::cin >> A_D;
	std::cin >> B_D;

	std::vector<long long> my_hash_table(array_size, -1);

	for (long i = 0; i < N; i++)
	{
		if (search(X, my_hash_table) == 1)
		{
			A = fast_mod(A + A_C, 1000);
			B = fast_mod(B + B_C, 1000000000000000);
		}
		else
		{
			put(X, my_hash_table);
			A = fast_mod(A + A_D, 1000);
			B = fast_mod(B + B_D, 1000000000000000);
		}

		X = fast_mod(X * A + B, 1000000000000000);

		/*if (i % 1000 == 0)
		{
			std::cout << "\nIter: " << i;
		}*/
		count_X_iter++;
	}

	std::cout << X << " " << A << " " << B << " ";

	//std::cout << "\nBucket count: " << my_set.bucket_count();

	return 0;

}
