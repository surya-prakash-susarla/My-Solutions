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
  vector<int> resultsArray(vector<int>& values, int k) {
    if (k == 1)
      return values;

    vector<int> answer;

    int fault = -1;
    int start = 0;

    for (int i = start + 1; i < k; i++) {
      if (values[i] != values[i - 1] + 1) {
        fault = i - 1;
      }
    }

    if (fault == -1)
      answer.push_back(values[start + k - 1]);
    else
      answer.push_back(-1);

    for (int i = k; i < values.size(); i++) {
      if (values[i] != values[i - 1] + 1) {
        fault = i - 1;
        answer.push_back(-1);
      } else {
        if (fault <= i - k) {
          answer.push_back(values[i]);
        } else {
          answer.push_back(-1);
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
