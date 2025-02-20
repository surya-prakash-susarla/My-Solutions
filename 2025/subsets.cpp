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
  typedef vector<int> vint;

  vector<vint> answer;

  void __rec__(int index, vint current, const vint& input) {
    if (index == input.size()) {
      answer.emplace_back(current);
      return;
    }

    __rec__(index + 1, current, input);
    current.push_back(input[index]);
    __rec__(index + 1, current, input);
  }

  vector<vector<int>> subsets(vector<int>& values) {
    __rec__(0, {}, values);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
