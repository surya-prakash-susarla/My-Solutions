class Solution {
 public:
  int missingNumber(vector<int>& input) {
    int rsum = (input.size() * (input.size() + 1)) / 2;

    int csum = 0;
    for (int i : input)
      csum += i;

    return rsum - csum;
  }
};
