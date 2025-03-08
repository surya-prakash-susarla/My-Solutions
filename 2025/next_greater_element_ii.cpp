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
  vector<int> input;
  vector<int> values;

  int search(int ind) {
    if (values[ind] != -2)
      return values[ind];
    int nind = (ind + 1) % input.size();
    if (input[nind] > input[ind]) {
      values[ind] = nind;
      return nind;
    } else {
      while (true) {
        nind = search(nind);
        if (input[nind] > input[ind]) {
          values[ind] = nind;
          return nind;
        }
      }
    }
  }

  vector<int> nextGreaterElements(vector<int>& nums) {
    this->input = nums;
    values = vector<int>(input.size(), -2);

    int maxval = INT_MIN;
    int ind = -1;
    for (int i = 0; i < input.size(); i++) {
      if (input[i] > maxval) {
        maxval = input[i];
        ind = i;
      }
    }
    values[ind] = ind;
    input[ind] = INT_MAX;
    for (int i = 0; i < input.size(); i++)
      search(i);

    input[ind] = maxval;
    vector<int> answer;
    for (int i = 0; i < values.size(); i++) {
      if (values[i] != i and input[values[i]] != input[i]) {
        answer.push_back(input[values[i]]);
      } else {
        answer.push_back(-1);
      }
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
