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
  vector<string> splitWordsBySeparator(vector<string>& input, char sep) {
    vector<string> answer;
    for (const string& i : input) {
      string current = "";
      for (char c : i) {
        if (c == sep) {
          if (not current.empty()) {
            answer.push_back(current);
          }
          current = "";
        } else {
          current += c;
        }
      }
      if (not current.empty())
        answer.emplace_back(current);
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
