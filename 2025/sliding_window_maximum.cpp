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
  vector<int> maxSlidingWindow(vector<int>& input, int k) {
    multiset<int> values;
    for (int i = 0; i < k; i++)
      values.insert(input[i]);

    vector<int> answer;

    for (int i = k; i < input.size(); i++) {
      answer.push_back(*values.rbegin());
      auto it = values.find(input[i - k]);
      values.erase(it);
      values.insert(input[i]);
    }

    answer.push_back(*values.rbegin());

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
