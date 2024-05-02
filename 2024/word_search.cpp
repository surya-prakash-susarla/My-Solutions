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
  bool __rec__(int i,
               int j,
               vector<vector<char>>& values,
               int index,
               const string& word) {
    if (index == word.size())
      return true;
    if (i < 0 or j < 0 or i >= values.size() or j >= values[0].size())
      return false;

    if (values[i][j] == word[index]) {
      char orig = values[i][j];
      values[i][j] = '@';
      bool result = __rec__(i, j - 1, values, index + 1, word) or
                    __rec__(i, j + 1, values, index + 1, word) or
                    __rec__(i - 1, j, values, index + 1, word) or
                    __rec__(i + 1, j, values, index + 1, word);
      values[i][j] = orig;
      return result;
    }
    return false;
  }

  bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (__rec__(i, j, board, 0, word))
          return true;
      }
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
