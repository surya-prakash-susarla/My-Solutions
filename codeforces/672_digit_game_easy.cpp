#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int llint;

llint __calc__()
{
    llint n;
    cin >> n;
    llint re = 0, ro = 0, be = 0, bo = 0;
    string input;
    cin >> input;
    for (llint i = 0; i < n; i++)
    {
        llint temp = input[i] - '0';
        if (i % 2 == 0)
        {
            if (temp % 2 == 0)
                re++;
            else
                ro++;
        }
        else
        {
            if (temp % 2 == 0)
                be++;
            else
                bo++;
        }
    }
    bool r_init = true;
    while (n > 1)
    {
        if (r_init)
        {
            if (re > 0)
                re--;
            else
                ro--;
        }
        else
        {
            if (bo > 0)
                bo--;
            else
                be--;
        }
        r_init = !r_init;
        n--;
    }
    return ro > 0 || bo > 0 ? 1 : 2;
}

int main()
{
    llint t;
    cin >> t;

    for (llint i = 0; i < t; i++)
    {
        cout << __calc__();
        if (i < t - 1)
            cout << endl;
    }

    return 0;
}