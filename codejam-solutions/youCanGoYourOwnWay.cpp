#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    int dimension;
    string current_path;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> dimension;
        cin >> current_path;
        for (int i = 0; i < current_path.size(); i++)
            if (current_path[i] == 'S')
                current_path[i] = 'E';
            else
                current_path[i] = 'S';
        cout << "Case #" << i << ": " << current_path;
        if (i < t)
            cout << endl;
    }
    return 0;
}