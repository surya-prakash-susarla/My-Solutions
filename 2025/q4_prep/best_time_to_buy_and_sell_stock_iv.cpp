class Solution {
 public:
  vector<vector<int>> memo;

  int __rec__(int index, int k, const vector<int>& input) {
    if (index == input.size())
      return 0;

    if (k <= 0)
      return 0;

    if (memo[index][k] != -1)
      return memo[index][k];

    int excl = __rec__(index + 1, k, input);

    int incl = 0;
    for (int i = index + 1; i < input.size(); i++) {
      if (input[i] > input[index]) {
        int current = (input[i] - input[index]) + __rec__(i + 1, k - 1, input);
        incl = max(incl, current);
      }
    }

    memo[index][k] = max(incl, excl);
    return memo[index][k];
  }

  int maxProfit(int k, vector<int>& prices) {
    memo = vector<vector<int>>(prices.size(), vector<int>(k + 1, -1));
    return __rec__(0, k, prices);
  }
};
