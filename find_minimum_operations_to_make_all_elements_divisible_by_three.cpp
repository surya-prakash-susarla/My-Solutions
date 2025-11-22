class Solution {
 public:
  int minimumOperations(vector<int>& input) {
    int answer = 0;
    for (int i : input) {
      if (i % 3 == 0)
        continue;

      int add = (3 - (i % 3));
      int sub = i % 3;
      answer += min(add, sub);
    }
    return answer;
  }
};
