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
  vector<int> findDuplicates(vector<int>& input) {
    int i = 0;
    vector<int> answer;
    while (i < input.size()) {
      if (input[i] == -1 or input[i] == i + 1) {
        i++;
      } else {
        int iocn = input[i] - 1;
        if (input[iocn] == input[i]) {
          answer.push_back(input[i]);
          input[i] = -1;
          i++;
        } else {
          swap(input[iocn], input[i]);
        }
      }
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
