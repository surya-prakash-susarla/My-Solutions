class Solution {
 public:
  int findJudge(int size, vector<vector<int>>& input) {
    vector<int> trust_value(size, 0);
    vector<bool> trusts(size, false);

    for (auto i : input) {
      trusts[i[0] - 1] = true;
      trust_value[i[1] - 1] += 1;
    }

    for (int i = 0; i < size; i++)
      if (not trusts[i] and trust_value[i] == size - 1)
        return i + 1;
    return -1;
  }
};