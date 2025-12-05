class Solution {
 public:
  int minOperations(vector<int>& input, int k) {
    int answer = 0;
    for (int i : input)
      answer += i;
    return answer % k;
  }
};
