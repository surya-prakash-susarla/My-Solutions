class Solution {
 public:
  map<int, int> memo;

  int climbStairs(int n) {
    if (memo.contains(n)) {
      return memo[n];
    }

    int answer;
    if (n == 0) {
      answer = 1;
    } else if (n > 1) {
      answer = climbStairs(n - 1) + climbStairs(n - 2);
    } else {
      answer = climbStairs(n - 1);
    }

    memo[n] = answer;
    return answer;
  }
};
