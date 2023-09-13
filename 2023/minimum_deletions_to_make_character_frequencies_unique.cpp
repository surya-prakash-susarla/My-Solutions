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
  int minDeletions(string input) {
    vector<int> chars(26);
    for (char c : input)
      chars[c - 'a']++;
    map<int, int> f;
    for (int i = 0; i < 26; i++)
      if (chars[i] != 0)
        f[chars[i]]++;

    int answer = 0;
    queue<int> req;

    for (int i = f.rbegin()->first; i > 0; i--) {
      if (f[i] > 1) {
        for (int j = 0; j < f[i] - 1; j++)
          req.push(i);
      }

      if (req.empty()) {
        auto it = f.lower_bound(i);
        if (it == f.begin()) {
          break;
        } else {
          it = prev(it);
          i = it->first + 1;
        }
      } else {
        if (f[i] == 1) {
          continue;
        } else if (f[i] == 0) {
          int top = req.front();
          req.pop();
          answer += (top - i);
        }
      }
    }

    for (; not req.empty(); req.pop())
      answer += req.front();

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
