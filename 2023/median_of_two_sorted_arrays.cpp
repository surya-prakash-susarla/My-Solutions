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
  inline int get_next_element(int& lp,
                              int& rp,
                              const vector<int>& input1,
                              const vector<int>& input2) {
    if (lp == input1.size())
      return input2[rp++];
    if (rp == input2.size())
      return input1[lp++];

    if (input1[lp] < input2[rp]) {
      return input1[lp++];
    } else {
      return input2[rp++];
    }
  }

  double findMedianSortedArrays(vector<int>& input1, vector<int>& input2) {
    int size_1 = input1.size();
    int size_2 = input2.size();

    int mi = (size_1 + size_2);
    bool get_next = false;
    if (mi % 2 == 0) {
      mi = (mi - 1) / 2;
      get_next = true;
    } else {
      mi /= 2;
    }

    double answer = -1;
    int count = 0;
    int lp = 0;
    int rp = 0;
    while (count != mi + 1) {
      answer = get_next_element(lp, rp, input1, input2);
      count++;
    }

    if (get_next) {
      int next = get_next_element(lp, rp, input1, input2);
      answer = ((double)(answer + next)) / 2;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
