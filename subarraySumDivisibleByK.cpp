class Solution {
 public:
  int subarraysDivByK(vector<int>& input, int div) {
    vector<int> values;
    int count = 0;
    for (int i = input.size() - 1; i > -1; i--) {
      vector<int> temp;
      temp.push_back(input[i]);
      if (input[i] % div == 0)
        count += 1;
      for (auto j : values) {
        int temp_value = j + input[i];
        if (temp_value % div == 0)
          count += 1;
        temp.push_back(temp_value);
      }
      values = temp;
    }
    return count;
  }
};