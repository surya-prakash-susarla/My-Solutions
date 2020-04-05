#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, b;
        cin >> n >> b;
        vector<int> values(n);
        for (int j = 0; j < n; j++)
            cin >> values[j];
        sort(values.begin(), values.end());
        int answer = 0;
        for (int j : values)
        {
            if (j > b)
                break;
            else
            {
                answer += 1;
                b -= j;
            }
        }
        cout << "Case #" << i << ": " << answer;
        if (i < t)
            cout << endl;
    }
    return 0;
}