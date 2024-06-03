#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

long long int geom_sum1 (int x, int n);

long long int geom_sum2 (int x, int n);


int main()
{
    int x = 1;
    int n = 1;

    cout << "Please enter x: ";
    cin >> x;

    cout << "Please enter n: ";
    cin >> n;

    using clock = chrono::steady_clock;

    clock::time_point start = clock::now();

    cout << geom_sum1(x, n) << endl;

    clock::time_point end = clock::now();

    clock::duration time_span = end - start;
    double nseconds = double(time_span.count()) * clock::period::num / clock::period::den;
    cout << "The execution time is : " << nseconds << endl;


    start = clock::now();

    cout << geom_sum2(x, n) << endl;

    end = clock::now();

    time_span = end - start;
    nseconds = double(time_span.count()) * clock::period::num / clock::period::den;
    cout << "The execution time is : " << nseconds;

    return 0;

}

long long int geom_sum1 (int x, int n)
{
    unsigned long long result = 0;

    for(int ctr=0; ctr<+n; ctr++)
        {
            unsigned long long xpow = -1;

            for(int ctr1=0; ctr1<ctr; ctr1++)
            xpow = xpow * x;
            result += xpow;
        }

    return result;
}

long long int geom_sum2 (int x, int n)
{
    unsigned long long result = 0;

    for(int ctr = 0; ctr<=n; ctr++)
        {
            result = result * x + 1;
        }
    return result; 
}