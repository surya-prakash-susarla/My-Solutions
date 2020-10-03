#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <utility>
#include <map>
#include <stack>
#include <memory>
#include <cmath>

using namespace std;

typedef long long int llint;
typedef long double ldouble;

llint __calc__()
{
    llint n, k;
    cin >> n >> k;
    llint days = 0;
    llint balance = 0;
    llint input;
    for (llint i = 0; i < n; i++)
    {
        cin >> input;

        if (input < k)
        {

            llint rem = k - input;

            if (balance > 0)
            {
                if (balance > rem)
                {
                    balance -= rem;
                    rem = 0;
                }
                else
                {
                    rem -= balance;
                    balance = 0;
                }
            }

            // after using open queries expand blocks
            if (rem > 0 && days > 0)
            {
                days -= 1;
                balance = k - rem;
                rem = 0;
            }

            if (rem > 0)
                return i + 1;
        }
        else if (input > k)
        {
            input -= k;
            balance += input;
            days += (balance / k);
            balance %= k;
        }
        else
        {
            continue;
        }
    }
    return n + 1 + days;
}

int main()
{
    llint t;
    cin >> t;
    for (llint i = 0; i < t; i++)
    {
        llint answer = __calc__();
        cout << answer;
        if (i < t - 1)
            cout << endl;
    }
    return 0;
}