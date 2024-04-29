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
  int minOperations(vector<int>& nums, int k) {
    bitset<32> req(k);

    vector<bitset<32>> values;
    for (int i : nums)
      values.emplace_back(bitset<32>(i));

    int answer = 0;

    for (int i = 0; i < 32; i++) {
      int count = 0;
      for (int j = 0; j < values.size(); j++) {
        if (values[j][i] == 1)
          count++;
      }
      if (req[i] == 1 and (count % 2 == 0))
        answer++;
      else if (req[i] == 0 and count % 2)
        answer++;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
