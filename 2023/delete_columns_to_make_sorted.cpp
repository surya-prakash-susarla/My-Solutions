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
  int minDeletionSize(vector<string>& values) {
    int answer = 0;

    for (int j = 0; j < values.begin()->size(); j++) {
      for (int i = 0; i < values.size() - 1; i++)
        if (values[i][j] > values[i + 1][j]) {
          answer++;
          break;
        }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
