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
  unordered_map<int, optional<vector<string>>> memo;

  optional<vector<string>> __rec__(int i,
                                   const string& input,
                                   const vector<string>& values) {
    if (i == input.size()) {
      return vector<string>(1);
    }
    {
      auto it = memo.find(i);
      if (it != memo.end()) {
        return it->second;
      }
    }
    vector<string> answer;
    for (int j = i + 1; j <= input.size(); j++) {
      const string current = input.substr(i, j - i);
      if (find(values.begin(), values.end(), current) == values.end())
        continue;
      optional<vector<string>> temp = __rec__(j, input, values);
      if (temp.has_value()) {
        for (string k : *temp) {
          if (not k.empty())
            answer.push_back(current + " " + k);
          else
            answer.push_back(current);
        }
      }
    }
    if (answer.empty()) {
      return nullopt;
    } else {
      return answer;
    }
  }

  vector<string> wordBreak(string input, vector<string>& values) {
    optional<vector<string>> answer = __rec__(0, input, values);
    return answer.has_value() ? *answer : vector<string>();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
