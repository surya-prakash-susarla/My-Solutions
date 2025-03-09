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
  vector<vector<int>> fourSum(vector<int>& input, int target) {
    typedef long long int llint;

    sort(input.begin(), input.end());

    unordered_map<llint, vector<int>> values;
    for (int i = 0; i < input.size(); i++)
      values[input[i]].push_back(i);

    auto get = [&](const vector<int>& values, int i, int j,
                   int k) -> optional<int> {
      for (int l : values)
        if (l != i and l != j and l != k)
          return l;
      return nullopt;
    };

    set<vector<int>> answer;

    for (int i = 0; i < input.size(); i++) {
      for (int j = i + 1; j < input.size(); j++) {
        for (int k = j + 1; k < input.size(); k++) {
          auto it = values.find((llint)target - input[i] - input[j] - input[k]);
          if (it != values.end()) {
            optional<int> retval = get(it->second, i, j, k);
            if (retval.has_value()) {
              vector<int> temp = {input[i], input[j], input[k], input[*retval]};
              sort(temp.begin(), temp.end());
              answer.insert(temp);
            }
          }
        }
      }
    }

    return vector<vector<int>>(answer.begin(), answer.end());
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
