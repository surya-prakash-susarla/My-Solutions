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
  vector<vector<int>> permute(vector<int>& values) {
    sort(values.begin(), values.end());
    vector<vector<int>> answer;
    do
      answer.emplace_back(values);
    while (next_permutation(values.begin(), values.end()));
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
