class Solution {
 public:
  int triangleNumber(vector<int>& input) {
    if (input.size() < 3)
      return 0;

    sort(input.begin(), input.end());

    int answer = 0;
    for (int i = 0; i < input.size(); i++) {
      for (int j = i + 1; j < input.size(); j++) {
        auto it = lower_bound(input.begin(), input.end(), input[i] + input[j]);

        if (it == input.end()) {
          answer += (input.size() - j - 1);
        } else {
          int d = (it - next(input.begin(), j)) - 1;
          if (d <= 0)
            continue;

          answer += d;
        }
      }
    }

    return answer;
  }
};
