class Solution {
 public:
  typedef long long ll;
  typedef vector<ll> vint;

  vector<optional<ll>> memo;

  ll maxval(const vint& input, const int index, const int k) {
    if (memo[index].has_value()) {
      return *memo[index];
    }

    ll answer;
    if (index + k > input.size()) {
      answer = numeric_limits<ll>::min();
    } else if (index + k == input.size()) {
      answer = input[index];
    } else {
      ll current = input[index] - input[index + k];
      ll next = maxval(input, index + k, k);

      if (next == numeric_limits<ll>::min()) {
        answer = current;
      } else {
        answer = max(current, current + next);
      }
    }

    memo[index] = answer;
    return answer;
  }

  long long maxSubarraySum(vector<int>& input, int k) {
    const int n = input.size();
    vector<ll> values(input.size(), 0);
    memo = vector<optional<ll>>(input.size());
    values[n - 1] = input[n - 1];

    for (int i = n - 2; i > -1; i--) {
      values[i] = input[i] + values[i + 1];
    }

    ll answer = numeric_limits<ll>::min();
    for (int i = 0; i < n; i++) {
      ll temp = maxval(values, i, k);
      answer = max(answer, temp);
    }

    return answer;
  }
};
