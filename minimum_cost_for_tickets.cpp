#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int calc(int index,
           int cost,
           vector<int>& memo,
           const vector<int>& days,
           const vector<int>& costs) {
    if (index >= days.size())
      return cost;

    if (memo[index] != -1)
      return memo[index];

    int one = calc(index + 1, 0, memo, days, costs);

    int temp = index + 1;

    while (temp < days.size() and days[temp] < days[index] + 7) {
      temp++;
    }
    int week = calc(temp, 0, memo, days, costs);

    while (temp < days.size() and days[temp] < days[index] + 30) {
      temp++;
    }
    int month = calc(temp, 0, memo, days, costs);

    memo[index] =
        cost + min(one + costs[0], min(week + costs[1], month + costs[2]));
    return memo[index];
  }

  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> memo(days.size(), -1);
    return calc(0, 0, memo, days, costs);
  }
};