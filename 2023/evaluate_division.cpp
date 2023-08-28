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
  static constexpr double minvalue = numeric_limits<double>::min();
  map<string, map<string, double>> cons;

  double __rec__(const string current, const string target, set<string> used) {
    if (cons.find(current) == cons.end())
      return minvalue;

    if (current == target)
      return 1;

    used.insert(current);

    {
      auto it = cons[current].find(target);
      if (it != cons[current].end())
        return it->second;
    }

    for (const pair<string, double>& i : cons[current]) {
      if (used.find(i.first) == used.end()) {
        double return_value = __rec__(i.first, target, used);
        if (return_value != minvalue)
          return i.second * return_value;
      }
    }

    return minvalue;
  }

  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& temp) {
    for (int i = 0; i < values.size(); i++) {
      string num = equations[i][0];
      string den = equations[i][1];
      double value = values[i];

      cons[num][den] = value;
      cons[den][num] = 1 / value;
    }

    vector<double> answer;
    for (int i = 0; i < temp.size(); i++) {
      string num = temp[i][0];
      string den = temp[i][1];

      double return_value = __rec__(num, den, set<string>());
      if (return_value != minvalue)
        answer.push_back(return_value);
      else
        answer.push_back(-1);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
