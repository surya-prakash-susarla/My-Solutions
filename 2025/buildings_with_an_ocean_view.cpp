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
  vector<int> findBuildings(vector<int>& input) {
    int maxvalue = INT_MIN;
    vector<int> answer;

    for (int i = input.size() - 1; i > -1; i--) {
      if (input[i] > maxvalue) {
        maxvalue = input[i];
        answer.push_back(i);
      }
    }

    reverse(answer.begin(), answer.end());

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
