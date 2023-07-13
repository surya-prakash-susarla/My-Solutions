#include <bits/stdc++.h>

using namespace std;

/* Test Cases
[2,-1,1,2,2]
[-1,2]
[-2,1,-1,-2,-2]
[-1,-2,-3,-4,-5]
[-100]
[5,5,5,5,5]
[1,-1,2,-2,3,-3,4,-5]
[-1,-1,-3]
[2,2,2,2]
[1,2,2,1]
[1,2,3,4,5,6,7,8,9,10]
[1000,1000,1000]
[-1000,-1000,-1000]
[-1,-1,-3]
*/

class Solution {
 public:
  int getIndex(int current, int jump, int limit) {
    if (jump > 0)
      return (current + jump) % limit;
    jump = 0 - (abs(jump) % limit);
    int temp = current + jump;
    if (temp < 0)
      temp = limit + temp;
    return temp % limit;
  }

  bool circularArrayLoop(vector<int>& input) {
    vector<int> cache(input.size(), -1);

    auto findIndex = [&]() -> optional<int> {
      for (int i = 0; i < cache.size(); i++)
        if (cache[i] == -1)
          return i;
      return nullopt;
    };

    optional<int> ci = findIndex();
    while (ci.has_value()) {
      bool is_pos = input[ci.value()] > 0;
      stack<int> path;
      vector<bool> visited(input.size(), false);
      path.push(ci.value());
      visited[ci.value()] = true;
      int ni = getIndex(ci.value(), input[ci.value()], input.size());
      while (cache[ni] == -1 and is_pos == (input[ni] > 0) and
             not visited[ni]) {
        path.push(ni);
        visited[ni] = true;
        ni = getIndex(ni, input[ni], input.size());
      }
      if ((cache[ni] == 1 or visited[ni]) and path.top() != ni)
        return true;
      while (not path.empty()) {
        cache[path.top()] = 0;
        path.pop();
      }
      ci = findIndex();
    }
    return false;
  }
};
