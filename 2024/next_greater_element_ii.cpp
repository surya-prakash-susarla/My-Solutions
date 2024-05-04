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
  vector<int> nextGreaterElements(vector<int>& values) {
    vector<int> temp(values);
    temp.insert(temp.end(), values.begin(), values.end());

    vector<int> answer(values.size());
    stack<int> temp_stack;

    for (int i = temp.size() - 1; i > -1; i--) {
      while (not temp_stack.empty() and temp_stack.top() <= temp[i])
        temp_stack.pop();

      if (i < answer.size())
        answer[i] = temp_stack.empty() ? -1 : temp_stack.top();

      temp_stack.push(temp[i]);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
