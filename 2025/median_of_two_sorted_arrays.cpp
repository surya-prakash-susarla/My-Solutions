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
  int get_and_move(int& left,
                   int& right,
                   const vector<int>& a,
                   const vector<int>& b) {
    if (left < a.size() and right < b.size()) {
      int answer;
      if (a[left] < b[right]) {
        answer = a[left];
        left++;
      } else {
        answer = b[right];
        right++;
      }
      return answer;
    } else if (left == a.size()) {
      const int answer = b[right];
      right++;
      return answer;
    } else {
      const int answer = a[left];
      left++;
      return answer;
    }
  }

  double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    int left = 0;
    int right = 0;

    int n = (a.size() + b.size());

    if (n % 2) {
      for (int i = 1; i < (n / 2) + 1; i++) {
        get_and_move(left, right, a, b);
      }
      return get_and_move(left, right, a, b);
    } else {
      for (int i = 1; i < n / 2; i++)
        get_and_move(left, right, a, b);

      int x = get_and_move(left, right, a, b);
      int y = get_and_move(left, right, a, b);
      return (double)(x + y) / 2;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
