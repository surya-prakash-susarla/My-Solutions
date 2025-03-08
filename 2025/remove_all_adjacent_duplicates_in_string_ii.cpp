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
  string removeDuplicates(string s, int k) {
    stack<pair<char, int>> values;

    for (char c : s) {
      if (not values.empty() and values.top().first == c) {
        pair<char, int> current = values.top();
        values.pop();
        current.second++;

        if (current.second == k) {
          // ignore this entry
        } else {
          values.push(current);
        }
      } else {
        values.push({c, 1});
      }
    }

    string answer;
    for (; not values.empty(); values.pop()) {
      answer += (string(values.top().second, values.top().first));
    }
    reverse(answer.begin(), answer.end());

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
