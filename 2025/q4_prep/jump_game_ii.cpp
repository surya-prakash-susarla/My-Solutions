class Solution {
 public:
  int jump(vector<int>& input) {
    vector<int> values(input.size(), INT_MAX);
    values[input.size() - 1] = 0;

    for (int i = input.size() - 2; i > -1; i--) {
      if (i + input[i] >= input.size()) {
        values[i] = 1;
      } else {
        int current = INT_MAX;
        for (int j = 1; j <= input[i]; j++) {
          current = min(current,
                        values[i + j] != INT_MAX ? values[i + j] + 1 : INT_MAX);
        }
        values[i] = current;
      }
    }

    return values[0];
  }
};
