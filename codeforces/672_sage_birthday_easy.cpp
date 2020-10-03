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

llint answer = 0 ;
vector<llint> answer_values;

void __print__(const vector<llint> &input)
{
    for (const auto &i : input)
        cout << i << " ";
    return;
}

void __calc__()
{
    llint n;
    cin >> n;
    vector<llint> input(n, -1);

    for (int i = 0; i < n; i++)
        cin >> input[i];

    sort(input.begin(), input.end());

    answer = (n - 1) / 2;

    if ( answer == 0 ) {
        answer_values = input ; 
        return;
    }

    answer_values.resize(n, -1);

    // -1 in the end to compensate for 0 based indexing
    llint ind = answer - 1;

    for (llint i = n - 2, j = ind; i > -1 && j > -1; i -= 2, j--)
    {
        answer_values[i] = input[j];
    }

    for (llint i = n - 1, j = n - 1; i > -1 && j > ind; i -= 2, j--)
    {
        answer_values[i] = input[j];
    }

    if ( n % 2 == 0 ) {
        answer_values[0] = input[ind+1];
    }

    return;
}

int main()
{
    __calc__();
    cout << answer << endl;
    __print__(answer_values);
    cout << endl;
    return 0;
}