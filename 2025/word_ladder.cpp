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
  int ladderLength(string start, string end, vector<string>& input) {
    auto it = find(input.begin(), input.end(), end);
    if (it == input.end())
      return 0;
    const int target = (it - input.begin());
    map<int, vector<int>> cons;
    int source = -1;
    {
      auto it = find(input.begin(), input.end(), start);
      if (it == input.end()) {
        input.push_back(start);
        source = (input.size() - 1);
      } else {
        source = (it - input.begin());
      }
    }

    auto are_connected = [](const string& a, const string& b) -> bool {
      bool missed = false;
      for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
          if (missed)
            return false;
          missed = true;
        }
      }
      return true;
    };

    for (int i = 0; i < input.size(); i++) {
      for (int j = i + 1; j < input.size(); j++) {
        if (are_connected(input[i], input[j])) {
          cons[i].push_back(j);
          cons[j].push_back(i);
        }
      }
    }

    vector<bool> used(input.size());

    int answer = 1;
    queue<int> current;
    current.push(source);

    while (not current.empty()) {
      queue<int> next;
      for (; not current.empty(); current.pop()) {
        int top = current.front();
        used[top] = true;
        if (top == target)
          return answer;
        for (int i : cons[top])
          if (not used[i])
            next.push(i);
      }
      swap(current, next);
      answer++;
    }

    return 0;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
