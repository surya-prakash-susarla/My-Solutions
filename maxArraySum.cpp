#include <bits/stdc++.h>

using namespace std;

typedef long long int llint;

vector<string> split_string(string);

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr)
{
    vector<llint> values;
    for (int i = 0; i < arr.size(); i++)
        values.push_back(arr[i]);
    values.push_back(0);
    values.push_back(0);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        llint current_value = max(max(values[i], values[i + 1]), max(values[i + 2], values[i + 2] + values[i]));
        values[i] = current_value;
    }
    return values[0];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = maxSubsetSum(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
