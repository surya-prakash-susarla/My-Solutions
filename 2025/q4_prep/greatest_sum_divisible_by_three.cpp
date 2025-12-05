class Solution {
 public:
  int maxSumDivThree(vector<int>& input) {
    if (input.size() == 1) {
      // handle here.
      if (input[0] % 3 == 0)
        return input[0];
      else
        return 0;
    }

    vector<int> current = {INT_MIN, INT_MIN, INT_MIN};
    const int n = input.size();

    {
      // setup the beginning.
      int current_bucket = (input[n - 1] % 3);
      current[current_bucket] = input[n - 1];
    }

    for (int i = n - 2; i > -1; i--) {
      int default_bucket = (input[i] % 3);
      vector<int> alts(3, INT_MIN);

      for (int j : current) {
        if (j == INT_MIN)
          continue;
        int sum = j + input[i];
        int new_bucket = (sum % 3);
        alts[new_bucket] = sum;
      }

      alts[default_bucket] = max(alts[default_bucket], input[i]);

      for (int j = 0; j < 3; j++)
        current[j] = max(current[j], alts[j]);
    }

    return current[0];
  }
};
