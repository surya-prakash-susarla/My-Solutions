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
  int getSumOfDigits(int n) {
    int answer = 0;
    while (n) {
      answer += n % 10;
      n /= 10;
    }
    return answer;
  }

  int maximumSum(vector<int>& input) {
    map<int, priority_queue<int>> values;
    for (int i : input)
      values[getSumOfDigits(i)].push(i);

    int answer = -1;

    for (auto i : values) {
      if (i.second.size() > 1) {
        int current = i.second.top();
        i.second.pop();
        current += i.second.top();
        answer = max(answer, current);
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
