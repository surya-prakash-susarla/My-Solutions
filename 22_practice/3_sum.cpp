#include <bits/stdc++.h>

using namespace std;

/* Test cases:
[-1,0,1,2,-1,-4]
[]
[0]
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,-2]
[9,1,1,1,1,1,-2,-2,-2,-2,3,3,3,3,-9,-9,-9,6,-6,-6]

*/

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& input) {
    if (input.size() < 3)
      return {};

    sort(input.begin(), input.end());
    set<int> temp(input.begin(), input.end());

    vector<vector<int>> answer;

    int lri = 0;
    vector<int> ui = {input[0]};
    for (int i = 1; i < input.size(); i++) {
      if (input[i] == input[lri]) {
        if (input[i] != 0 and i - lri == 1) {
          auto it = temp.find(0 - (2 * input[i]));
          if (it != temp.end())
            answer.push_back({input[i], input[i], *it});
        } else if (input[i] == 0 and i - lri == 2) {
          answer.push_back({0, 0, 0});
        }
      } else {
        lri = i;
        ui.push_back(input[i]);
      }
    }

    // cout << "size of repeat answers : " << answer.size() << endl;
    // cout << "size of chars : " << ui.size() << endl;

    temp = set<int>(ui.begin(), ui.end());
    for (int i = 0; i < ui.size(); i++) {
      for (int j = i + 1; j < ui.size(); j++) {
        auto it = temp.find(0 - ui[i] - ui[j]);
        if (it != temp.end() and distance(temp.begin(), it) > j) {
          answer.push_back({ui[i], ui[j], *it});
        }
      }
    }

    return answer;
  }
};
