// Ilya Dubitskiy



#include "stdafx.h"
#include <iostream>
#include <fstream>

#include <time.h>



#include <string>
#include <vector>
#include <limits>

long queue_size = 0;

//#include "edx-io.hpp"


//using namespace std;

/*void make_pr_queue(std::vector<long>& my_queue)
{
	
}*/

void swap(std::vector< std::pair<long, long> >& my_queue, long i, long j, std::vector<long>& str_numb_new_index)
{

	str_numb_new_index[my_queue[i].second] = j;
	str_numb_new_index[my_queue[j].second] = i;
	std::pair<long, long> tmp = my_queue[i];
	my_queue[i] = my_queue[j];
	my_queue[j] = tmp;


}

void min_heapify(std::vector< std::pair<long, long> >& my_queue, long i, std::vector<long>& str_numb_new_index)
{
	//long queue_size = my_queue.size();
	
	long left = 2 * i;
	long right = 2 * i + 1;
	long smallest = i;

	if (left < queue_size && my_queue[left].first < my_queue[smallest].first)
	{
		smallest = left; 
	}
	if (right < queue_size && my_queue[right].first < my_queue[smallest].first)
	{
		smallest = right;
	}
	if (smallest != i)
	{
		swap(my_queue, i, smallest, str_numb_new_index);

		min_heapify(my_queue, smallest, str_numb_new_index);
	}

}

void build_heap(std::vector< std::pair<long, long> >& my_queue, std::vector<long>& str_numb_new_index)
{
	//long queue_size = my_queue.size();

	for (long i = (queue_size - 1) / 2; i > -1; i--)
	{
		min_heapify(my_queue, i, str_numb_new_index);
	}
}


void extract_min(std::vector< std::pair<long, long> >& my_queue, std::vector<long>& str_numb_new_index)
{
	//long queue_size = my_queue.size();

	if (queue_size == 0)
	{
		std::cout << "*\n";
		return;
	}

	std::cout << my_queue[0].first << "\n";
	str_numb_new_index[my_queue[queue_size - 1].second] = 0;
	my_queue[0] = my_queue[queue_size - 1];
	//my_queue.pop_back();
	queue_size--;

	min_heapify(my_queue, 0,  str_numb_new_index);

	return;
}

void decr_key(std::vector< std::pair<long, long> >& my_queue, long i, long key, std::vector<long>& str_numb_new_index)
{
	my_queue[i].first = key;

	while (i > 0 && my_queue[i / 2].first > my_queue[i].first)
	{
		swap(my_queue, i / 2, i, str_numb_new_index);
		i = i / 2;
	}
}

void ins_el(std::vector< std::pair<long, long> >& my_queue, long key, std::vector<long>& str_numb_new_index, long i)
{
	queue_size++;
	my_queue[queue_size - 1] = std::pair<long, long>(std::numeric_limits<long>::max(), i);
	decr_key(my_queue, queue_size - 1, key, str_numb_new_index);

}




int _tmain(int argc, _TCHAR* argv[])
{

	std::ifstream cin("input.txt");
	std::ofstream cout("output.txt");
	std::cin.rdbuf(cin.rdbuf());
	std::cout.rdbuf(cout.rdbuf());

	//clock_t t;
	//t = clock();

	long numb_oper = 0;
	//std::vector<std::string> all_data;


	std::cin >> numb_oper;
	std::vector< std::pair<long, long> > my_queue(numb_oper, std::pair<long, long>(0, 0));
	std::vector<long> str_numb_new_index(numb_oper, 0);
	
	my_queue.reserve(numb_oper);

	char cur_oper = 0;
	long curr_value = 0;
	long curr_number = 0;
	int heap_build_needed = 1;

	//long queue_size = 0;

	for (long i = 0; i < numb_oper; i++)
	{
		std::cin >> cur_oper;

		if (cur_oper == 'A')
		{
			//std::stringstream number();
			
			std::cin >> curr_value;
			if (heap_build_needed == 1)
			{
				my_queue[queue_size] = std::pair<long, long>(curr_value, i);
				str_numb_new_index[i] = queue_size;
				build_heap(my_queue, str_numb_new_index);
				heap_build_needed = 0;
				queue_size++;
			}
			else
			{
				str_numb_new_index[i] = queue_size;
				ins_el(my_queue, curr_value, str_numb_new_index, i);
			}
			
		}
		if (cur_oper == 'X')
		{
			//std::stringstream number();

			if (heap_build_needed == 1)
			{
				build_heap(my_queue, str_numb_new_index);
				heap_build_needed = 0;
			}
			extract_min(my_queue, str_numb_new_index);
		}
		if (cur_oper == 'D')
		{
			std::cin >> curr_number;
			curr_number = curr_number - 1;
			std::cin >> curr_value;


			if (heap_build_needed == 1)
			{
				build_heap(my_queue, str_numb_new_index);
				heap_build_needed = 0;
			}

			long new_el_index = str_numb_new_index[curr_number];
			decr_key(my_queue, new_el_index, curr_value, str_numb_new_index);

			//build_heap(my_queue);

			/*for (unsigned long j = 0; j < my_queue.size(); j++)
			{
				if (my_queue[j].second == curr_number)
				{
					decr_key(my_queue, j, curr_value, str_numb_new_index);
					break;
				}
			}*/

		}

	}

	return 0;

}
