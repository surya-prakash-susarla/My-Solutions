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
  int minNumberOperations(vector<int>& input) {
    int prev = 0;
    int answer = 0;
    for (int i = 0; i < input.size(); i++) {
      if (input[i] >= prev) {
        answer += (input[i] - prev);
      }
      prev = input[i];
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
