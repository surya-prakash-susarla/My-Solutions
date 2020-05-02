#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long int long_int;

long_int __calc__()
{
    long_int k;
    cin >> k;
    vector<long_int> values(k);
    for_each(values.begin(), values.end(), [](long_int &current_value) {
        cin >> current_value;
    });
    long_int peak = 0;
    for (long_int i = 1; i < k - 1; i++)
    {
        if (values[i] > values[i - 1] && values[i] > values[i + 1])
        {
            peak++;
            i += 1;
        }
    }
    return peak;
}

int main()
{
    long_int t;
    cin >> t;
    for (long_int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": " << __calc__();
        if (i < t)
            cout << endl;
    }
    return 0;
}