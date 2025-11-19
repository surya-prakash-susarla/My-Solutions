class Solution {
 public:
  int findFinalValue(vector<int>& input, int x) {
    unordered_set<int> values;
    for (int i : input)
      values.insert(i);

    while (values.contains(x)) {
      x = x * 2;
    }

    return x;
  }
};
