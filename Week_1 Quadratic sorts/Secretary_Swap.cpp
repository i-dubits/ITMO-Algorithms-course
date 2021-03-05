// Week_1_task_5_ver_1

#include "stdafx.h"
#include <iostream>
#include <fstream>



//#include "edx-io.hpp"


using namespace std;


class welfare {

public:

	long wel_ammount;
	long id_init;
	
	welfare(long wel_ammount = 0, long id_init = 0);
	welfare& operator= (welfare arg_1);

};

welfare::welfare(long w, long id_in) :wel_ammount(w), id_init(id_in)
{}

welfare& welfare::operator=(welfare arg_1)
{
	wel_ammount = arg_1.wel_ammount;
	id_init = arg_1.id_init;

	return *this;
}


void swap(welfare& arg_1, welfare& arg_2)
{
	welfare temp = arg_1;
	arg_1 = arg_2;
	arg_2 = temp;
}

// true if first arg lesser than second arg
bool if_less(welfare arg_1, welfare arg_2)
{
	return arg_1.wel_ammount < arg_2.wel_ammount;
}


int _tmain(int argc, _TCHAR* argv[])
{

	ifstream cin("input.txt");
	ofstream cout("output.txt");

	long  n = 0;
	
	//cout << "\n Type n: ";
	cin >> n;

	welfare* my_struct;
		
	my_struct = new welfare[n];
	
	//cout << "\n Type array: ";

	for (long i = 0; i < n; i++)
	{
		cin >> my_struct[i].wel_ammount;
		my_struct[i].id_init = i;
	}



	//cout << "\n Number of elements: " << n << "\n Init array: ";
	/*for (int i = 0; i < n; i++)
	{
		cout << "  " << init_array[i];
	}*/

	int subseq_l = 1;
	while (subseq_l < n / 3)
	{
		subseq_l = subseq_l * 3 + 1;
	}

	while (subseq_l >= 1)
	{

		for (int i = subseq_l; i < n; i++)
		{
			for (int j = i; j >= subseq_l && if_less(my_struct[j], my_struct[j - subseq_l]); j -= subseq_l)
			{
				swap(my_struct[j], my_struct[j - subseq_l]);
				cout << "Swap elements at indices " << j - subseq_l + 1 << " and " << j + 1 << ".\n";
			}
		}

		subseq_l = subseq_l / 3;
	}


	cout << "No more swaps needed.\n";

	//cout << " \n Res index:  ";
	
		
	//cout << "\n";

	
	for (int i = 0; i < n; i++)
	{
		cout <<  my_struct[i].wel_ammount << "  ";
	}

	delete[] my_struct;
	
	//cout << "\n";
	//system ("pause");
	return 0;
}
