// Ilya Dubitskiy
// Week_10_task_1_ver_1.cpp 

#include <iostream>
#include <fstream>

#include <string>
#include <vector>




std::vector<long> prefix_calc_2(std::string my_string)
{
    //long i = 0;
    //long j = 1;

    long n = my_string.length();

    std::vector<long> pref(n, 0);
    //pref.reserve(n);

    long k = 0;

    for (long i = 1; i <= n - 1; i++)
    {
        k = pref[i - 1];
        
        while (k > 0 && my_string[i] != my_string[k])
        {
            k = pref[k - 1];
        }

        if (my_string[i] == my_string[k])
        {
            k++;
        }

        pref[i] = k;
    }

    return pref;
}


int main()
{
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    std::cin.rdbuf(cin.rdbuf());
    std::cout.rdbuf(cout.rdbuf());

    std::string my_string;

    std::getline(cin, my_string);

    std::vector<long> pref;

    pref = prefix_calc_2(my_string);

    for (auto p : pref)
    {
        std::cout << p << " ";
    }

    //std::cout << my_string;
    
}


