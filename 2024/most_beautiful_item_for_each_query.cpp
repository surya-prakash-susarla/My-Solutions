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
  vector<int> maximumBeauty(vector<vector<int>>& input, vector<int>& q) {
    map<int, int> values;

    sort(input.begin(), input.end(),
         [](const vector<int>& a, const vector<int>& b) -> bool {
           if (a[0] == b[0])
             return a[1] < b[1];
           return a[0] < b[0];
         });

    for (const vector<int>& i : input) {
      auto it = values.lower_bound(i[0]);
      if (it == values.end()) {
        if (values.size() > 0)
          values[i[0]] = max(i[1], values.rbegin()->second);
        else
          values[i[0]] = i[1];
      } else if (it->first == i[0]) {
        values[i[0]] = max(i[1], it->second);
      } else {
        if (it == values.begin()) {
          values[i[0]] = i[1];
        } else {
          it = prev(it);
          int temp = i[1];
          while (it != values.begin()) {
            temp = max(temp, it->second);
            it = prev(it);
          }
          temp = max(temp, it->second);
          values[i[0]] = temp;
        }
      }

      values[i[0]] = max(values[i[0]], i[1]);
    }

    vector<int> answer;

    for (int i : q) {
      auto it = values.lower_bound(i);

      if (it == values.end()) {
        answer.push_back(values.rbegin()->second);
      } else if (it->first == i) {
        answer.push_back(it->second);
      } else {
        if (it == values.begin()) {
          answer.push_back(0);
        } else {
          answer.push_back(prev(it)->second);
        }
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
