class Solution {
 public:
  int findFinalValue(vector<int>& nums, int original) {
    set<int> values;

    bool original_found = false;

    for (const int& i : nums) {
      if (i == original)
        original_found = true;
      else if (i % 2 == 0)
        values.insert(i);
    }

    if (!original_found)
      return original;
    else {
      int answer = original * 2;
      while (values.find(answer) != values.end()) {
        answer *= 2;
      }
      return answer;
    }
  }
};