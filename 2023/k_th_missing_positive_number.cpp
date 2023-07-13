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
  int findKthPositive(vector<int>& arr, int k) {
    vector<int> seq(2001);
    iota(seq.begin(), seq.end(), 1);
    vector<int> answer(20000);
    set_difference(seq.begin(), seq.end(), arr.begin(), arr.end(),
                   answer.begin());
    return answer[k - 1];
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
