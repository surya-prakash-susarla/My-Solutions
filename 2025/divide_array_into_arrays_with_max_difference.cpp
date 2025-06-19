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
  vector<vector<int>> divideArray(vector<int>& input, int k) {
    sort(input.begin(), input.end());

    vector<vector<int>> answer;
    for (auto it = input.begin(); it != input.end(); it = next(it, 3)) {
      vector<int> temp(it, next(it, 3));
      if (*temp.rbegin() - *temp.begin() > k) {
        return {};
      }
      answer.push_back(temp);
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
