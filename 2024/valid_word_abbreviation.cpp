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
  bool validWordAbbreviation(string word, string abbr) {
    int wi = 0;

    int num = 0;
    for (int i = 0; i < abbr.size(); i++) {
      if (isalpha(abbr[i])) {
        if (num != 0) {
          wi += num;
        }
        num = 0;

        if (wi >= word.size() or word[wi] != abbr[i])
          return false;

        wi++;
      } else {
        if (num == 0 and abbr[i] == '0')
          return false;
        num = (num * 10) + (abbr[i] - '0');
      }
    }

    if (num > 0)
      wi += num;

    if (wi != word.size())
      return false;

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
