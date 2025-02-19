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
  int target;

  string answer;

  int counter = 0;

  void __rec__(int n, char prev, string current) {
    if (n == 0) {
      counter++;
      if (counter == target)
        answer = current;

      return;
    }
    set<char> avail = {'a', 'b', 'c'};
    if (prev != '@')
      avail.erase(prev);

    for (char c : avail) {
      __rec__(n - 1, c, current + c);
      if (not answer.empty())
        return;
    }
  }

  string getHappyString(int n, int k) {
    if (3 * pow(2, n - 1) < k)
      return "";

    target = k;

    __rec__(n, '@', "");

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
