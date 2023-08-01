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
  int majorityElement(vector<int>& values) {
    map<int, int> temp;
    for (int i : values)
      temp[i]++;

    int answer;
    int count = 0;
    for (auto i : temp)
      if (i.second > count) {
        count = i.second;
        answer = i.first;
      }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
