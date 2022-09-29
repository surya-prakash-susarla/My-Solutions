#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool exist(vector<vector<char>>& values, string word) {
    for (int i = 0; i < values.size(); i++)
      for (int j = 0; j < values[0].size(); j++)
        if (values[i][j] == word[0] && __rec__(i, j, 0, values, word))
          return true;
    return false;
  }

  bool __rec__(int x,
               int y,
               int loc,
               vector<vector<char>>& values,
               const string& word) {
    if (x < 0 or y < 0 or x >= values.size() or y >= values[0].size())
      return false;

    if (values[x][y] == '@' or values[x][y] != word[loc])
      return false;

    if (loc + 1 == word.size())
      return true;

    char orig = values[x][y];
    values[x][y] = '@';

    if (x - 1 > -1 and __rec__(x - 1, y, loc + 1, values, word))
      return true;
    if (x + 1 < values.size() and __rec__(x + 1, y, loc + 1, values, word))
      return true;
    if (y - 1 > -1 and __rec__(x, y - 1, loc + 1, values, word))
      return true;
    if (y + 1 < values[0].size() and __rec__(x, y + 1, loc + 1, values, word))
      return true;

    values[x][y] = orig;

    return false;
  }
};

int main() {
  return 0;
}
