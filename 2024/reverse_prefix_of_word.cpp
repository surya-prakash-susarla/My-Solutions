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
  string reversePrefix(string word, char ch) {
    int ind = 0;
    for (int i = 0; i < word.size(); i++)
      if (word[i] == ch) {
        ind = i;
        break;
      }

    string prefix = word.substr(0, ind + 1);
    reverse(prefix.begin(), prefix.end());

    return prefix + word.substr(ind + 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
