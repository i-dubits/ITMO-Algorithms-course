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


long max(long a, long b)
{
    return (a > b) ? a : b;
}

long min(long a, long b)
{
    return (a > b) ? b : a;
}


std::vector<long> z_calc(std::string my_string)
{
    long n = my_string.length();

    std::vector<long> z_func(n, 0);

    long left = 0;
    long right = 0;

    for (long i = 1; i <= n - 1; i++)
    {
        z_func[i] = max( 0, min( right - i, z_func[i - left] ) );

        while (i + z_func[i] < n && my_string[z_func[i]] == my_string[i + z_func[i]])
        {
            z_func[i]++;
        }

        if (i + z_func[i] > right)
        {
            left = i;
            right = i + z_func[i];
        }
    }

    return z_func;
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
    std::vector<long> z_func;

    //pref = prefix_calc_2(my_string);

    z_func = z_calc(my_string);

    for (auto p = z_func.begin(); p != z_func.end(); p++)
    {
        if (p == z_func.begin())
        {
            p++;
        }
        std::cout << *p << " ";
    }

    //std::cout << my_string;
    
}

