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
  unordered_map<int, bool> memo;

  bool find(int ind, const string& input, int target) {
    if (stoi(input.substr(ind, input.size())) == target)
      return true;

    for (int i = ind + 1; i < input.size(); i++) {
      string current = input.substr(ind, i - ind);
      int value = stoi(current);
      if (find(i, input, target - value)) {
        return true;
      }
    }

    return false;
  }

  bool is_valid(int i) {
    auto it = memo.find(i);
    if (it != memo.end())
      return it->second;

    string conv = to_string(i * i);
    bool result = find(0, conv, i);
    memo[i] = result;
    return result;
  }

  int punishmentNumber(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
      if (is_valid(i)) {
        answer += (i * i);
      }
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
