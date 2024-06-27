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
  bool does_word_exist(int i,
                       int j,
                       int ind,
                       vector<vector<char>>& input,
                       const string& word) {
    if (ind == word.size())
      return true;

    if (i < 0 or j < 0 or i >= input.size() or j >= input[0].size())
      return false;

    if (input[i][j] == word[ind]) {
      const char original_char = input[i][j];
      input[i][j] = '@';
      bool result = does_word_exist(i - 1, j, ind + 1, input, word) or
                    does_word_exist(i + 1, j, ind + 1, input, word) or
                    does_word_exist(i, j - 1, ind + 1, input, word) or
                    does_word_exist(i, j + 1, ind + 1, input, word);
      input[i][j] = original_char;
      return result;
    } else {
      return false;
    }
  }

  vector<pair<int, int>> search(char c, const vector<vector<char>>& input) {
    vector<pair<int, int>> answer;
    for (int i = 0; i < input.size(); i++)
      for (int j = 0; j < input[i].size(); j++)
        if (input[i][j] == c)
          answer.emplace_back(make_pair(i, j));
    return answer;
  }

  vector<string> findWords(vector<vector<char>>& input, vector<string>& words) {
    vector<string> answer;
    for (const string& k : words) {
      vector<pair<int, int>> locations = search(k[0], input);
      for (pair<int, int> ind : locations)
        if (does_word_exist(ind.first, ind.second, 0, input, k)) {
          answer.emplace_back(k);
          break;
        }
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
