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
  vector<int> intersect(vector<int>& a, vector<int>& b) {
    map<int, int> counts;
    for (int i : a)
      counts[i]++;

    vector<int> answer;
    for (int i : b)
      if (counts[i]-- > 0)
        answer.push_back(i);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
