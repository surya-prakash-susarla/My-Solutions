class Solution {
 public:
  bool check_prev(string input, int size) {
    if (size == 0)
      return true;
    set<string> values;
    for (int i = 1; i <= size; i++) {
      string init(size - i, '0');
      for (int j = 0; j <= input.size() - i; j++)
        values.insert(init + input.substr(j, i));
    }
    if (values.size() == int(1 << size))
      return true;
    return false;
  }

  bool queryString(string value, int input) {
    int bits = (int)log2(input) + 1;
    bool prev_exists = check_prev(value, bits - 1);

    if (prev_exists) {
      // check for current numbers
      int base = int(1 << bits - 1);
      vector<bool> nums(input - base + 1, false);
      for (int i = 0; i <= value.size() - bits; i++) {
        int current_index = stoi(value.substr(i, bits), nullptr, 2) - base;
        if (current_index < nums.size())
          nums[current_index] = true;
      }
      for (auto i : nums)
        if (not i)
          return false;
      return true;
    }
    return false;
  }
};