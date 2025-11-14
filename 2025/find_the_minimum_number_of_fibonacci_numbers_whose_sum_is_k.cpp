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
  int findMinFibonacciNumbers(int n) {
    int a = 1;
    int b = 1;

    vector<int> values;
    values.push_back(1);
    while (a + b <= n) {
      values.push_back(a + b);
      int temp = a;
      a = b;
      b = temp + b;
    }

    int answer = 0;

    reverse(values.begin(), values.end());

    for (int i : values) {
      if (i <= n) {
        n -= i;
        answer++;
      }

      if (n == 0)
        break;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
