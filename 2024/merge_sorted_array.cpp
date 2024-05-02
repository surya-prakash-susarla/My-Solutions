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
  void merge(vector<int>& a, int m, vector<int>& b, int n) {
    int end = n + m - 1;
    n--;
    m--;
    while (n > -1 or m > -1) {
      if (n > -1 and m > -1) {
        if (a[m] > b[n])
          a[end--] = a[m--];
        else
          a[end--] = b[n--];
      } else if (n > -1) {
        a[end--] = b[n--];
      } else {
        a[end--] = a[m--];
      }
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
