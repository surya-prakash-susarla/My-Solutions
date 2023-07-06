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
  int longestSubarray(vector<int>& values) {
    vector<int> temp;
    temp.push_back(-1);

    for (int i = 0; i < values.size(); i++) {
      if (values[i] == 0)
        temp.push_back(i);
    }
    temp.push_back(values.size());

    if (temp.size() == 2)
      return values.size() - 1;

    int answer = 0;
    for (int i = 1; i < temp.size() - 1; i++) {
      answer = max(answer,
                   (temp[i] - temp[i - 1] - 1) + (temp[i + 1] - temp[i] - 1));
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
