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
  int subarraySum(vector<int>& input, int k) {
    vector<int> values(input.size() + 1, 0);
    for (int i = 0; i < input.size(); i++) {
      values[i + 1] += input[i] + values[i];
    }

    int answer = 0;

    for (int i = 0; i < values.size(); i++) {
      int req = values[i] + k;
      for (int j = i + 1; j < values.size(); j++) {
        if (values[j] == req)
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
