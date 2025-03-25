#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Solution {
 public:
  typedef pair<int, int> pint;

  vector<pint> merge_ranges(const vector<pint>& input) {
    vector<pint> answer;
    pint current = input[0];
    for (int i = 1; i < input.size(); i++) {
      if (current.second > input[i].first) {
        current.second = max(current.second, input[i].second);
      } else {
        answer.push_back(current);
        current = input[i];
      }
    }
    answer.push_back(current);
    return answer;
  }

  bool checkValidCuts(int n, vector<vector<int>>& input) {
    vector<pint> x_ranges;
    vector<pint> y_ranges;
    for (auto i : input) {
      x_ranges.push_back(make_pair(i[0], i[2]));
      y_ranges.push_back(make_pair(i[1], i[3]));
    }

    sort(x_ranges.begin(), x_ranges.end(), [](const pint& a, const pint& b) {
      if (a.first == b.first)
        return a.second < b.second;
      return a.first < b.first;
    });

    sort(y_ranges.begin(), y_ranges.end(), [](const pint& a, const pint& b) {
      if (a.first == b.first)
        return a.second < b.second;
      return a.first < b.first;
    });

    auto print_ranges = [](const vector<pint>& ref) {
      for (auto i : ref)
        cout << i.first << " " << i.second << endl;
    };

    vector<pint> x = merge_ranges(x_ranges);
    vector<pint> y = merge_ranges(y_ranges);

    return x.size() >= 3 or y.size() >= 3;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
