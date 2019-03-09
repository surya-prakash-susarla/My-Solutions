#include <iostream>
#include <set>
#include <utility>
using namespace std;

set<pair<int, int>> locations;

void calc(int x, int y, int moves)
{
    if (x < 0 or y < 0 or x > 9 or y > 9)
        return;
    if (moves == 0)
    {
        locations.insert(make_pair(x, y));
        return;
    }
    calc(x - 1, y + 2, moves - 1);
    calc(x + 1, y + 2, moves - 1);
    calc(x - 2, y + 1, moves - 1);
    calc(x - 2, y - 1, moves - 1);
    calc(x + 2, y + 1, moves - 1);
    calc(x + 2, y - 1, moves - 1);
    calc(x - 1, y - 2, moves - 1);
    calc(x + 1, y - 2, moves - 1);
    return;
}

int main()
{
    int i, j, n;
    cin >> i >> j >> n;
    i -= 1, j -= 1;
    calc(i, j, n);
    cout << locations.size() << endl;
    return 0;
}