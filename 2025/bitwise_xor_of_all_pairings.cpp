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
  int xorAllNums(vector<int>& a, vector<int>& b) {
    map<int, int> values;
    for (int i : a)
      values[i] += (b.size());

    for (int i : b)
      values[i] += (a.size());

    int answer = 0;
    for (auto i : values) {
      if (i.second % 2)
        answer ^= i.first;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
