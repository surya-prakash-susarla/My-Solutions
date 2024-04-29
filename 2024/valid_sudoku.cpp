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
  bool isValidSudoku(vector<vector<char>>& input) {
    // row validation.
    for (int i = 0; i < 9; i++) {
      set<char> temp;
      int count = 0;
      for (int j = 0; j < 9; j++) {
        if (input[i][j] != '.') {
          temp.insert(input[i][j]);
          count++;
        }
      }
      if (temp.size() != count)
        return false;
    }
    // col validation.
    for (int j = 0; j < 9; j++) {
      set<char> temp;
      int count = 0;
      for (int i = 0; i < 9; i++) {
        if (input[i][j] != '.') {
          temp.insert(input[i][j]);
          count++;
        }
      }
      if (temp.size() != count)
        return false;
    }

    // sub-grid validation.
    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        set<char> temp;
        int count = 0;
        for (int k = i; k < i + 3; k++) {
          for (int l = j; l < j + 3; l++) {
            if (input[k][l] != '.') {
              temp.insert(input[k][l]);
              count++;
            }
          }
        }
        if (temp.size() != count)
          return false;
      }
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
