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
  int longestIdealString(string s, int k) {
    vector<int> temp(26, 0);
    for (int i = 0; i < s.size(); i++) {
      int curr = 0;
      for (int j = (int)(s[i] - k < 'a' ? 'a' : s[i] - k);
           j <= (int)(s[i] + k > 'z' ? 'z' : s[i] + k); j++)
        curr = max(curr, temp[j - 'a']);
      temp[s[i] - 'a'] = curr + 1;
    }
    int answer = 0;
    for (int i : temp)
      answer = max(answer, i);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
