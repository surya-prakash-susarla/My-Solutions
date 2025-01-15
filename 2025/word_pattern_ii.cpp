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
  // int max_pattern_size = -1;

  bool __rec__(int pattern_ind,
               int source_ind,
               const string& pattern,
               const string& source,
               unordered_map<char, string> values) {
    if (source_ind == source.size())
      return pattern_ind == pattern.size();

    {
      // if pattern is already assigned to current char.
      auto it = values.find(pattern[pattern_ind]);
      if (it != values.end()) {
        const string current_substring =
            source.substr(source_ind, it->second.size());
        if (current_substring != it->second)
          return false;
        return __rec__(pattern_ind + 1, source_ind + it->second.size(), pattern,
                       source, values);
      }
    }

    unordered_set<string> assigned_values;
    for (auto i : values)
      assigned_values.insert(i.second);

    for (int i = 1; source_ind + i <= source.size(); i++) {
      unordered_map<char, string> temp = values;
      const string current_string = source.substr(source_ind, i);

      if (assigned_values.contains(current_string))
        continue;

      temp[pattern[pattern_ind]] = source.substr(source_ind, i);

      const bool result =
          __rec__(pattern_ind + 1, source_ind + i, pattern, source, temp);
      if (result)
        return true;
    }

    return false;
  }

  bool wordPatternMatch(string pattern, string source) {
    return __rec__(0, 0, pattern, source, {});
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
