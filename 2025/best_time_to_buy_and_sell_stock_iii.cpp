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
  int maxProfit(vector<int>& input) {
    vector<int> right(input.size());
    {
      vector<int> temp = input;
      for (int i = input.size() - 2; i > -1; i--) {
        temp[i] = max(temp[i], temp[i + 1]);
        right[i] = max(temp[i] - input[i], right[i + 1]);
      }
    }

    vector<int> left(input.size());
    {
      vector<int> temp = input;
      for (int i = 1; i < input.size(); i++) {
        temp[i] = min(temp[i], temp[i - 1]);
        left[i] = max(input[i] - temp[i], left[i - 1]);
      }
    }

    int answer = 0;
    for (int i = 0; i < input.size(); i++)
      answer = max(answer, left[i] + right[i]);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
