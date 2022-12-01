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
  bool halvesAreAlike(string s) {
    auto is_vowel = [](char c) {
      static vector<int> temp = {'a', 'e', 'i', 'o', 'u',
                                 'A', 'E', 'I', 'O', 'U'};
      return find(temp.begin(), temp.end(), c) != temp.end();
    };
    int first = 0;
    for (int i = 0; i < (s.size() / 2); i++)
      if (is_vowel(s[i]))
        first++;

    int second = 0;
    for (int i = s.size() / 2; i < s.size(); i++)
      if (is_vowel(s[i]))
        second++;

    return first == second;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
