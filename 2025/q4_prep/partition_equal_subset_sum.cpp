class Solution {
 public:
  map<pair<int, int>, bool> memo;

  bool is_valid(int index, int required, const vector<int>& input) {
    if (index >= input.size())
      return false;

    if (required == 0)
      return true;

    {
      auto it = memo.find({index, required});
      if (it != memo.end())
        return it->second;
    }

    const bool answer = is_valid(index + 1, required - input[index], input) or
                        is_valid(index + 1, required, input);
    memo[{index, required}] = answer;
    return answer;
  }

  bool canPartition(vector<int>& input) {
    int total = 0;
    for (int i : input)
      total += i;

    if (total % 2)
      return false;

    return is_valid(0, total / 2, input);
  }
};
