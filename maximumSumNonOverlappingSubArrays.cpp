#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int calc(int index,
           int sum_value,
           int l,
           int m,
           const vector<int>& input,
           const vector<pair<int, int>>& values) {
    if (index == input.size() and (l != 0 or m != 0))
      return -1;
    if (l == 0 and m == 0)
      return sum_value;
    int skip_value = calc(index + 1, sum_value, l, m, input, values);

    // try to fill l value
    int l_value = -1;
    if (l != 0 and index + l <= input.size())
      l_value =
          calc(index + l, sum_value + values[index].first, 0, m, input, values);

    // try to fill m value
    int m_value = -1;
    if (m != 0 and index + m <= input.size())
      m_value = calc(index + m, sum_value + values[index].second, l, 0, input,
                     values);

    return max(skip_value, max(l_value, m_value));
  }

  int maxSumTwoNoOverlap(const vector<int>& input, int l, int m) {
    vector<pair<int, int>> values(input.size(), {-1, -1});
    int temp = 0;
    for (int i = 0; i < l; i++)
      temp += input[i];
    values[0].first = temp;
    for (int i = 1; i <= input.size() - l; i++) {
      temp -= input[i - 1];
      temp += input[i + l - 1];
      values[i].first = temp;
    }
    temp = 0;
    for (int i = 0; i < m; i++)
      temp += input[i];
    values[0].second = temp;
    for (int i = 1; i <= input.size() - m; i++) {
      temp -= input[i - 1];
      temp += input[i + m - 1];
      values[i].second = temp;
    }
    return calc(0, 0, l, m, input, values);
  }
};