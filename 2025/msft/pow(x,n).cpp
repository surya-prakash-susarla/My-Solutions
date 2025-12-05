class Solution {
 public:
  map<long long int, double> memo;

  double myPow(double x, long long int n) {
    if (n == 0)
      return 1;

    if (n == 1)
      return x;

    if (memo.contains(n))
      return memo[n];

    double answer;
    bool neg = false;
    if (n < 0) {
      neg = true;
      n = 0 - n;
    }
    if (n % 2) {
      answer = myPow(x, n / 2) * myPow(x, (n / 2) + 1);
    } else {
      double temp = myPow(x, n / 2);
      answer = temp * temp;
    }

    memo[n] = answer;

    if (neg)
      return (double)1 / answer;

    return answer;
  }
};
