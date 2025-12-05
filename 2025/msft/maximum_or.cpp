class Solution {
 public:
  long long maximumOr(vector<int>& input, int k) {
    vector<long long> pre(input.size());
    pre[0] = input[0];

    for (int i = 1; i < input.size(); i++) {
      pre[i] = input[i] | pre[i - 1];
    }

    vector<long long> suf(input.size());
    suf[input.size() - 1] = input.back();

    for (int i = input.size() - 2; i > -1; i--) {
      suf[i] = input[i] | suf[i + 1];
    }

    long long answer = numeric_limits<long long>::min();

    for (int i = 0; i < input.size(); i++) {
      long long p = (i - 1 > -1) ? pre[i - 1] : 0;
      long long s = (i + 1 < input.size()) ? suf[i + 1] : 0;

      long long current = input[i] * pow(2, k);
      long long result = p | s | current;
      answer = max(answer, result);
    }

    return answer;
  }
};
