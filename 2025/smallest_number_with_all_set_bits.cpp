class Solution {
 public:
  int smallestNumber(int n) {
    int answer = 0;
    int p = 0;
    while (n > 0) {
      answer += pow(2, p++);
      n /= 2;
    }
    return answer;
  }
};
