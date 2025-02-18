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
  int minMeetingRooms(vector<vector<int>>& input) {
    typedef vector<int> vint;
    typedef vector<vint> vvint;

    sort(input.begin(), input.end(), [](const vint& a, const vint& b) {
      if (a[0] == b[0])
        return a[1] < b[1];
      return a[0] < b[0];
    });

    priority_queue<int, vint, greater<int>> values;

    int answer = 0;

    for (const vint& i : input) {
      for (; not values.empty() and values.top() <= i[0]; values.pop())
        ;
      values.push(i[1]);
      answer = max(answer, (int)values.size());
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
