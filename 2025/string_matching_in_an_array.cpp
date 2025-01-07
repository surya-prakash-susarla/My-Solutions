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
  bool is_valid(const string& target, const string& source) {
    if (target.size() == source.size())
      return target == source;
    if (target.size() < source.size())
      return false;

    for (int i = 0; i < target.size(); i++) {
      bool failed = false;
      int j, k;
      for (j = 0, k = i; not failed and j < source.size() and k < target.size();
           k++, j++) {
        if (target[k] != source[j]) {
          failed = true;
        }
      }
      if (not failed and j == source.size())
        return true;
    }
    return false;
  }

  vector<string> stringMatching(vector<string>& words) {
    vector<string> answer;
    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words.size(); j++) {
        if (i != j and is_valid(words[j], words[i])) {
          answer.emplace_back(words[i]);
          break;
        }
      }
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
