#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// DEBUG METHOD
void print_chars(vector<int> count)
{
    cout << "Printing chars " << endl;
    for (int i = 0; i < count.size(); i++)
        if (count[i] != 0)
            cout << char(i + 'A') << " ";
    cout << endl;
    return;
}

bool check_anagram(int start_index, int end_index, string value, vector<int> count)
{
    for (int i = start_index; i != end_index; i++)
    {
        count[value[i] - 'A'] -= 1;
        if (count[value[i] - 'A'] < 0)
            return false;
    }
    for (int i : count)
        if (i > 0)
            return false;
    return true;
}

int trivial_check(string a, string b)
{
    int count = 0;
    vector<int> count_values(26, 0);
    for (char c : a)
        count_values[c - 'A']++;
    vector<int> complete_count(count_values);
    for (char c : b)
    {
        if (count_values[c - 'A'] > 0)
        {
            count += count_values[c - 'A'];
            count_values[c - 'A'] = 0;
        }
        complete_count[c - 'A'] -= 1;
    }
    bool no_match = false;
    for (int i : complete_count)
        if (i != 0)
            no_match = true;
    if (not no_match)
        count += 1;
    return count;
}

void freq_update(int start, int len, string a, vector<int> &values)
{
    // cout << " freq update " << endl;
    if (start == 0)
    {
        for (int i = 0; i < len; i++)
        {
            // cout << a[i] - 'A' << endl;
            values[a[i] - 'A'] += 1;
            // cout << values[a[i] - 'A'] << endl;
        }
        //    cout << "im after update" << endl;
        //    print_chars(values);
        return;
    }
    else
    {
        values[a[start - 1] - 'A'] -= 1;
        values[a[start + len - 1] - 'A'] += 1;
        return;
    }
    return;
}

int total_count(string a, string b)
{
    int total_count = 0;
    total_count += trivial_check(a, b);
    // cout << "Trivial check : " << total_count << endl;
    for (int len = 2; len < a.size(); len++)
    {
        vector<int> count_values(26, 0);
        // cout << "LENGTH : " << len << endl;
        for (int start_index = 0; start_index <= a.size() - len; start_index++)
        {
            // cout << "Parent substring : " << a.substr(start_index, len) << endl;
            freq_update(start_index, len, a, count_values);
            // print_chars(count_values);
            for (int k = 0; k <= b.size() - len; k++)
            {
                // cout << "checking substring : " << b.substr(k, len) << endl;
                if (check_anagram(k, k + len, b, count_values))
                {
                    // cout << "Accepted " << endl;
                    total_count += 1;
                    break;
                }
            }
        }
    }
    return total_count;
}

int main()
{
    // cout << total_count(a, b) << endl;
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        cout << "Case #" << k << ": " << total_count(a, b) << endl;
    }
    return 0;
}