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
  void sortColors(vector<int>& values) {
    int red = 0;
    int white = 0;
    int blue = 0;
    for (int i : values) {
      if (i == 0)
        red++;
      else if (i == 1)
        white++;
      else
        blue++;
    }
    int index = 0;
    for (int i = 0; i < red; i++)
      values[index++] = 0;
    for (int i = 0; i < white; i++)
      values[index++] = 1;
    for (int i = 0; i < blue; i++)
      values[index++] = 2;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
