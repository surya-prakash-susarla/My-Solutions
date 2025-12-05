class Solution {
 public:
  typedef vector<int> vint;
  typedef vector<vint> vvint;

  int trav(int i, int j, const int ident, vvint& ref) {
    if (i < 0 or j < 0 or i >= ref.size() or j >= ref[0].size())
      return 0;

    if (ref[i][j] != 1)
      return 0;

    ref[i][j] = ident;
    int answer = 1;
    answer += trav(i - 1, j, ident, ref);
    answer += trav(i + 1, j, ident, ref);
    answer += trav(i, j - 1, ident, ref);
    answer += trav(i, j + 1, ident, ref);
    return answer;
  }

  map<int, int> counter;

  int get_counts(int i, int j, const vvint& input) {
    set<int> values;
    if (i - 1 > -1)
      values.insert(input[i - 1][j]);
    if (j - 1 > -1)
      values.insert(input[i][j - 1]);
    if (i + 1 < input.size())
      values.insert(input[i + 1][j]);
    if (j + 1 < input[0].size())
      values.insert(input[i][j + 1]);

    int answer = 0;
    for (int i : values)
      answer += counter[i];

    return answer + 1;
  }

  int largestIsland(vector<vector<int>>& input) {
    int ident = 2;
    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input[0].size(); j++) {
        if (input[i][j] == 1) {
          int count = trav(i, j, ident, input);
          counter[ident] = count;
          ident++;
        }
      }
    }
    counter[0] = 0;

    int answer = INT_MIN;
    for (auto i : counter)
      answer = max(answer, i.second);

    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input[0].size(); j++) {
        if (input[i][j] == 0) {
          answer = max(answer, get_counts(i, j, input));
        }
      }
    }

    return answer;
  }
};
