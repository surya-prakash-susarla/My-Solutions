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
  vector<int> sortByBits(vector<int>& values) {
    vector<int> answer(values.begin(), values.end());
    sort(answer.begin(), answer.end(), [](const int& a, const int& b) {
      bitset<32> a_value(a);
      bitset<32> b_value(b);
      if (a_value.count() == b_value.count())
        return a < b;
      return a_value.count() < b_value.count();
    });
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
