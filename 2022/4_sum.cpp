#include <bits/stdc++.h>

using namespace std;

/* Test cases
[1,0,-1,0,-2,2]
0
[2,2,2,2,2]
8
[-5,5,4,-3,0,0,4,-2]
4
[2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2]
8
*/

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& input, int target) {
    typedef pair<int, int> pint;
    typedef vector<pint> vpint;

    int size = input.size();

    sort(input.begin(), input.end());

    const int maxvalue = numeric_limits<int>::max();

    int rc = 1;
    int prev = input[0];
    for (int i = 1; i < size; i++) {
      if (input[i] != prev) {
        rc = 1;
        prev = input[i];
      } else {
        rc++;
        if (rc > 4)
          input[i] = maxvalue;
      }
    }

    vector<int> temp;
    for (int i : input)
      if (i != maxvalue)
        temp.push_back(i);

    input = temp;
    size = input.size();

    map<int, vpint> values;
    for (int i = 0; i < size - 1; i++)
      for (int j = i + 1; j < size; j++)
        values[input[i] + input[j]].push_back({i, j});

    set<vector<int>> answer;

    for (int i = 0; i < size - 3; i++)
      for (int j = i + 1; j < size - 2; j++) {
        auto it = values.find(target - input[i] - input[j]);
        if (it != values.end()) {
          for (const pint& k : it->second) {
            if (k.first > j and k.second > j) {
              answer.insert(
                  {input[i], input[j], input[k.first], input[k.second]});
            }
          }
        }
      }

    return vector<vector<int>>(answer.begin(), answer.end());
  }
};
