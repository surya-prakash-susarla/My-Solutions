#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef unsigned long long int long_int;

long_int __calc__()
{
    long_int n, k;
    cin >> n >> k;
    vector<long_int> diffs(n - 1);
    long_int current, prev;
    for (long_int i = 0; i < n; i++)
    {
        cin >> current;
        if (i > 0)
        {
            diffs[i - 1] = current - prev;
        }
        prev = current;
    }
    long_int min_diff = 1;
    long_int max_diff = *max_element(diffs.begin(), diffs.end());
    long_int solution_diff = -1;
    while (min_diff <= max_diff)
    {
        long_int current_diff = (max_diff + min_diff) / 2;
        long_int current_moves_required = 0;
        for_each(diffs.begin(), diffs.end(), [&current_moves_required, &current_diff](const long_int &value) {
            if (value < current_diff)
                return;
            else
            {
                current_moves_required += (ceil((double)value / current_diff) - 1);
            }
        });

        if (current_diff == solution_diff)
            break;
        if (current_moves_required > k)
        {
            min_diff = current_diff+1;
        }
        else
        {
            solution_diff = current_diff;
            max_diff = current_diff-1;
        }
    }
    return solution_diff;
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