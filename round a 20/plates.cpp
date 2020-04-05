#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int rec(int index, int plates, const vector<vector<int>> &values, vector<vector<int>> &memo)
{
    if (index == values.size())
        return 0;
    if (plates == 0)
        return 0;
    
    if (memo[index][plates] != -1)
        return memo[index][plates];

    int answer = rec(index + 1, plates, values, memo);
    int current_value = 0, n_plates = plates;
    for (auto it = values[index].rbegin(); it != values[index].rend() && n_plates > 0; it++)
    {
        current_value += *it;
        n_plates -= 1;
        answer = max(answer, current_value + rec(index + 1, n_plates, values, memo));
    }
    memo[index][plates] = answer;
    return answer;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {

        int n, k, p;
        cin >> n >> k >> p;

        vector<vector<int>> values(n, vector<int>(k));
        for (int j = 0; j < n; j++)
            for (int l = k - 1; l > -1; l--)
                cin >> values[j][l];

        vector<vector<int>> memo(values.size(), vector<int>(p+1, -1));
        int answer = rec(0, p, values, memo);
        cout << "Case #" << i << ": " << answer;
        if (i < t)
            cout << endl;
    }
    return 0;
}