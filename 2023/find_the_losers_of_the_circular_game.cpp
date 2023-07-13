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
  vector<int> circularGameLosers(int n, int k) {
    int ok = k;
    vector<int> values(n + 1, 0);

    int current = 1;
    int rep = 1;

    while (true) {
      // cout << "current : " << current << endl;

      if (values[current] == 1)
        break;

      values[current] = 1;

      k = rep * ok;

      current = (current + k) % (n);

      if (current == 0)
        current = n;

      rep++;
    }

    vector<int> answer;
    for (int i = 1; i <= n; i++)
      if (values[i] == 0)
        answer.push_back(i);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
