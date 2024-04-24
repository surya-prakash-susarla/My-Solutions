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
  int tribonacci(int n) {
    if (n < 3)
      return n == 0 ? 0 : 1;

    queue<int> temp;
    temp.push(0);
    temp.push(1);
    temp.push(1);

    n -= 3;
    while (n > 0) {
      int csum = 0;
      for (queue<int> i = temp; not i.empty(); i.pop())
        csum += i.front();

      temp.pop();
      temp.push(csum);
      n--;
    }

    int answer = 0;
    for (queue<int> i = temp; not i.empty(); i.pop())
      answer += i.front();

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
