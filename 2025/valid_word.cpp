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
  bool isValid(string word) {
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int count = 0;
    int vow_found = false;
    int con_found = false;

    for (char c : word) {
      if (not isalnum(c))
        return false;

      if (isalpha(c)) {
        if (not vowels.contains(tolower(c))) {
          con_found = true;
        } else {
          vow_found = true;
        }
      }

      count++;
    }

    return count >= 3 and vow_found and con_found;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
