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
  int countPairs(vector<int>& input, int k) {
    int answer = 0;
    for (int i = 0; i < input.size() - 1; i++) {
      for (int j = i + 1; j < input.size(); j++) {
        if (input[i] == input[j] and (i * j) % k == 0)
          answer++;
      }
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
