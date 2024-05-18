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
  vector<int> maxSlidingWindow(vector<int>& values, int k) {
    unordered_map<int, int> valid;
    priority_queue<int> temp;
    vector<int> answer;

    for (int i = 0; i < k; i++) {
      valid[values[i]]++;
      temp.push(values[i]);
    }

    answer.push_back(temp.top());

    for (int i = k; i < values.size(); i++) {
      int remove_value = values[i - k];
      valid[remove_value]--;
      temp.push(values[i]);
      valid[values[i]]++;

      while (valid[temp.top()] <= 0)
        temp.pop();

      answer.push_back(temp.top());
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
