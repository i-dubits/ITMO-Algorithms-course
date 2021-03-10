// Ilya Dubitskiy
// Week_8_task_4_ver_4

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
#include <unordered_map>
#include <map>

//#include <functional>

// based on https://codeforces.com/blog/entry/4898

int count_setbits(int N)

{
	int cnt = 0;

	while (N > 0)

	{
		cnt += (N & 1);

		N = N >> 1;
	}

	return cnt;

}


long string_hash_test(long mult, std::string my_str)
{
	long rv = 0;
	//long a = my_str.length();
	for (unsigned long i = 0; i < my_str.length(); i++)
	{
		rv = mult * rv + my_str[i];
	}
	return rv;
}

std::string make_init_string(long Q, long N)
{
	//long N = 1 << Q;
	std::string res= "";
	for (int i = 0; i <= N; i++)
	{
		res += 'a' + count_setbits(i) % 2;
	}
	return res;
}


std::unordered_set<std::string> find_all_diff_str_with_given_hash(std::string my_string, long base, long hash)
{
	//std::vector<std::string> my_vect_final;
	std::unordered_set<std::string> res;

	for (unsigned long k = 0; k < my_string.length(); k += 16)
	{
		for (unsigned long j = 0; k + j < my_string.length(); j += 16)
		{
			std::string curr_substr = my_string.substr(k, j);
			long curr_hash = string_hash_test(base, curr_substr);

			if (curr_hash == hash)
			{
				res.insert(curr_substr);
			}
			//std::cout << "\n" << my_map[curr_hash];
		}
	}

	return res;
}

int main()
{
	std::ifstream cin("input.txt");
	std::ofstream cout("output.txt");
	std::cin.rdbuf(cin.rdbuf());
	std::cout.rdbuf(cout.rdbuf());

	std::string my_string = make_init_string(11, 1 << 11);

	//std::cout << my_string << "\n";

	std::string string_1 = "abbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaab";
	std::string string_2 = "abbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaab";
	std::string string_3 = "baababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaab";
	std::string string_4 = "abbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaab";
	std::string string_5 = "abbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaab";
	std::string string_6 = "abbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaab";
	std::string string_7 = "baababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaab";
	std::string string_8 = "abbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaab";

	std::vector<std::string> all_strings;
	all_strings.push_back(string_1);
	all_strings.push_back(string_2);
	all_strings.push_back(string_3);
	all_strings.push_back(string_4);
	all_strings.push_back(string_5);
	all_strings.push_back(string_6);
	all_strings.push_back(string_7);
	all_strings.push_back(string_8);

	long N = 0;
	std::cin >> N;
	long count = 0;

	for (long i1 = 0; i1 < all_strings.size(); i1++)
	{
		for (long i2 = 0; i2 < all_strings.size(); i2++)
		{
			for (long i3 = 0; i3 < all_strings.size(); i3++)
			{
				for (long i4 = 0; i4 < all_strings.size(); i4++)
				{
					for (long i5 = 0; i5 < all_strings.size(); i5++)
					{
						for (long i6 = 0; i6 < all_strings.size(); i6++)
						{
							count++;
							if (count > N)
							{
								exit(0);
							}
							std::cout << all_strings[i1]+ all_strings[i2]+ all_strings[i3]+ all_strings[i4]+ all_strings[i5]+ all_strings[i6] << "\n";
							//std::cout << "HASH: " << string_hash_test(555, all_strings[i1] + all_strings[i2] + all_strings[i3] + all_strings[i4] + all_strings[i5] + all_strings[i6]) << "\n";

									
						}
					}
				}
			}
		}
	}
	

	/*std::cout << "\nTEST\n";
	std::cout << "\nStrings hashes\n";
	for (auto p : all_strings)
	{
		std::cout << string_hash_test(7, p) << "\n";
	}

	std::cout << "\nStrings sums hashes\n";

	for (long i = 0; i < all_strings.size(); i++)
	{
		for (long k = 0; k < all_strings.size(); k++)
		{
			std::cout << string_hash_test(1000, all_strings[i] + all_strings[k]) << "\n";
		}
	}*/
	


	/*for (unsigned long k = 0; k < my_string.length(); k+=16)
	{
		for (unsigned long j = 0; k + j < my_string.length(); j+=16)
		{
			std::string curr_substr = my_string.substr(k, j);
			long curr_hash = string_hash_test(7, curr_substr);

			if (my_map_str.find(curr_hash) == my_map_str.end())
			{
				my_map_str[curr_hash] = curr_substr;
			}
			else if(curr_substr != "")
			{
				if (hash_count.find(curr_hash) == hash_count.end())
				{
					hash_count[curr_hash] = 1;
				}
				else
				{
					hash_count[curr_hash]++;
				}
				my_vect_final.push_back(curr_substr);
			}
			
			
			//std::cout << "\n" << my_map[curr_hash];
		}
	}
	std::vector<std::unordered_set<std::string>> all_good_strings_sets;
	for (auto p = hash_count.begin(); p != hash_count.end(); p++)
	{
		std::unordered_set<std::string> diff_str_given_hash_base;
		std::unordered_set<std::string> good_strings;
		if (p->second > 10)
		{
			diff_str_given_hash_base = find_all_diff_str_with_given_hash(my_string, 7, p->first);

			//std::unordered_set<std::string> diff_str_given_hash_base;
			//diff_str_given_hash_base = find_all_diff_str_with_given_hash(my_string, 7, 1186783744);

			good_strings = diff_str_given_hash_base;

			for (long i = 2; i <= 1023; i++)
			{
				auto p = diff_str_given_hash_base.begin();
				long curr_hash = string_hash_test(i, *p);
				p++;
				while (p != diff_str_given_hash_base.end())
				{

					if (curr_hash != string_hash_test(i, *p))
					{
						good_strings.erase(*p);
					}
					p++;

				}
			}
			all_good_strings_sets.push_back(good_strings);
		}
	}

	// Choose the best from good

	unsigned long the_largest_set_size = 0;
	std::unordered_set<std::string> best_strings;
	for (auto p : all_good_strings_sets)
	{
		if (the_largest_set_size <= p.size())
		{
			the_largest_set_size = p.size();
			best_strings = p;
		}

		std::cout << "\n\n Numb of strings " << p.size();
		std::string first_string = *p.begin();
		std::cout << "\n String size " << first_string.size() << "\n";

		for (auto p_set : p)
		{
			std::cout << p_set << "\n";
		}
	}*/

	

	/*std::cout << "\nBest strings: \n";
	for (auto p = best_strings.begin(); p != best_strings.end(); p++)
	{
		std::cout << "\n" << *p;
	}*/

	//std::unordered_map<long, std::string> my_map_final_all_mult;
	//std::unordered_map<long, long> count;

	/*my_map_final_all_mult = my_map_final;

	
	for (long i = 2; i < 1023; i++)
	{
		auto p = my_map_final.find(-1608748800);
		long curr_hash = string_hash_test(i, p->second);
		p++;

		while(p != my_map_final.end())
		{

			if (curr_hash != string_hash_test(i, p->second))
			{
				my_map_final_all_mult.erase(p->first);
			}
			p++;
		}
	}*/



	/*for (auto p = my_vect_final.begin(); p != my_vect_final.end(); p++)
	{

		std::cout << "Substring: " << *p  << "\n";

	}*/
	
	/*for (auto p = my_map_str.begin(); p != my_map_str.end(); p++)
	{

		std::cout << "Hash: " << p->first << "\n";
		std::cout << "Substring: " << p->second << "\n";

	}*/

	/*long max = 0;
	long max_hash = 0;
	long max_diff_strings = 0;
	long max_diff_strings_hash = 0;
	std::vector<std::string> all_strings;

	for (auto p = hash_count.begin(); p != hash_count.end(); p++)
	{
		std::unordered_set<std::string> diff_str_given_hash_base;
		if (p->second > 10)
		{
			diff_str_given_hash_base = find_all_diff_str_with_given_hash(my_string, 7, p->first);
		}
		if (max_diff_strings <= diff_str_given_hash_base.size())
		{
			max_diff_strings = diff_str_given_hash_base.size();
			max_diff_strings_hash = p->first;
		}

		if (max <= p->second)
		{
			max = p->second;
			max_hash = p->first;
		}
		std::cout << "\nMax hash " << p->first << " Max count " << p->second;
		
	}
	std::cout << "\nMax count: " << max << " Hash of max " << max_hash << "\n";
	
	std::unordered_set<std::string> diff_str_given_hash_base_max = find_all_diff_str_with_given_hash(my_string, 7, max_diff_strings_hash);

	std::cout << "\nBEST DIFF STRINGS " << " Their hash: " << max_diff_strings_hash ;
	for (auto p = diff_str_given_hash_base_max.begin(); p != diff_str_given_hash_base_max.end(); p++)
	{
		std::cout << "\n" << *p;
	}*/

	//std::cout << "\n INT " << sizeof(int) << " LONG " << sizeof(long);


	return 0;

}
