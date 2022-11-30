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
  bool uniqueOccurrences(vector<int>& values) {
    unordered_map<int, int> temp;
    for (int i : values) {
      temp[i]++;
    }
    set<int> temp2;
    for (const pair<int, int>& i : temp)
      temp2.insert(i.second);

    return temp2.size() == temp.size();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
