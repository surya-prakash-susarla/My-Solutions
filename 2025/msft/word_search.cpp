class Solution {
 public:
  bool __rec__(int i,
               int j,
               int ti,
               vector<vector<char>>& input,
               const string& target) {
    if (ti == target.size())
      return true;

    if (i < 0 or j < 0 or i >= input.size() or j >= input[0].size())
      return false;

    if (input[i][j] != target[ti])
      return false;

    char orig = input[i][j];
    input[i][j] = '@';

    bool result = __rec__(i - 1, j, ti + 1, input, target) or
                  __rec__(i, j - 1, ti + 1, input, target) or
                  __rec__(i + 1, j, ti + 1, input, target) or
                  __rec__(i, j + 1, ti + 1, input, target);

    input[i][j] = orig;

    return result;
  }

  bool exist(vector<vector<char>>& input, string word) {
    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input[0].size(); j++) {
        if (__rec__(i, j, 0, input, word)) {
          return true;
        }
      }
    }
    return false;
  }
};
