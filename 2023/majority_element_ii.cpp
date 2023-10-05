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
  vector<int> majorityElement(vector<int>& input) {
    const int req = (input.size() / 3);
    map<int, int> f;
    set<int> answer;
    for (int i : input) {
      f[i]++;
      if (f[i] > req)
        answer.insert(i);
    }
    return vector<int>(answer.begin(), answer.end());
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
