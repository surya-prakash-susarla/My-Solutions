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
  string get_value(int i) {
    switch (i) {
      case 0:
        return "Gold Medal";
      case 1:
        return "Silver Medal";
      case 2:
        return "Bronze Medal";
      default:
        return to_string(i + 1);
    }
  }

  vector<string> findRelativeRanks(vector<int>& score) {
    priority_queue<pair<int, int>> temp;
    for (int i = 0; i < score.size(); i++) {
      temp.push({score[i], i});
    }

    vector<string> answer(score.size());
    int i = 0;
    while (not temp.empty()) {
      const pair<int, int> current = temp.top();
      temp.pop();
      answer[current.second] = get_value(i++);
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
