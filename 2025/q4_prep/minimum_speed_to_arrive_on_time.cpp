class Solution {
 public:
  int minSpeedOnTime(vector<int>& input, double req) {
    int l = 1;
    int r = 10000000;

    auto is_valid = [&](const int x) -> bool {
      double total = 0;
      for (int i = 0; i < input.size() - 1; i++) {
        total += ceil((double)input[i] / x);
      }
      total += ((double)input.back() / x);

      return total <= req;
    };

    int answer = INT_MAX;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (is_valid(mid)) {
        answer = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return answer == INT_MAX ? -1 : answer;
  }
};
