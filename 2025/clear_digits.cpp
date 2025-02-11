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
  string clearDigits(string s) {
    stack<char> values;

    for (char c : s)
      if (c >= '0' and c <= '9')
        values.pop();
      else
        values.push(c);

    string answer;
    for (; not values.empty(); values.pop())
      answer += values.top();

    reverse(answer.begin(), answer.end());

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
