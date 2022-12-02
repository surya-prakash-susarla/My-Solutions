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
  bool closeStrings(string input, string target) {
    if (input.size() != target.size())
      return false;

    set<char> target_chars;
    unordered_map<char, int> target_f;
    for (char c : target) {
      target_f[c]++;
      target_chars.insert(c);
    }

    set<char> input_chars;
    unordered_map<char, int> input_f;
    for (char c : input) {
      input_f[c]++;
      input_chars.insert(c);
    }

    if (input_chars != target_chars)
      return false;

    map<int, int> req;

    for (const pair<char, int>& i : target_f) {
      auto it = input_f.find(i.first);
      if (it == input_f.end())
        return false;
      if (it->second != i.second) {
        req[it->second]++;
        req[i.second]--;
      }
    }

    for (const pair<int, int>& i : req)
      if (i.second != 0)
        return false;

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
