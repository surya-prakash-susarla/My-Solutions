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
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> answer;
    int ti = 0;

    for (int i = 1; i <= n; i++) {
      if (target[ti] == i) {
        answer.emplace_back("Push");
        ti++;
      } else {
        answer.emplace_back("Push");
        answer.emplace_back("Pop");
      }
      if (ti == target.size())
        break;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
