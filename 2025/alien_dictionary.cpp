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
  bool is_prefix(const string& a, const string& b) {
    return a.size() > b.size() and a.substr(0, b.size()) == b;
  }

  string alienOrder(vector<string>& words) {
    unordered_map<char, set<char>> cons;
    vector<int> con_count(26);

    for (auto i : words)
      for (auto j : i)
        cons[j];

    for (int i = 0; i < words.size() - 1; i++) {
      const string& a = words[i];
      const string& b = words[i + 1];

      if (is_prefix(a, b))
        return "";

      for (int j = 0; j < min(a.size(), b.size()); j++) {
        if (a[j] != b[j]) {
          if (not cons[a[j]].contains(b[j])) {
            cons[a[j]].insert(b[j]);
            con_count[b[j] - 'a'] += 1;
          }
          break;
        }
      }
    }

    string answer;
    queue<char> current;
    for (auto i : cons)
      if (con_count[i.first - 'a'] == 0)
        current.push(i.first);

    while (not current.empty()) {
      char temp = current.front();
      current.pop();

      answer += temp;

      for (auto j : cons[temp]) {
        con_count[j - 'a']--;
        if (con_count[j - 'a'] == 0)
          current.push(j);
      }
    }

    return answer.size() < cons.size() ? "" : answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
