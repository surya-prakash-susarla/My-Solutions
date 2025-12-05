class Solution {
 public:
  int solve(int start, int end, const vector<int>& input) {
    if (start > end)
      return INT_MIN;

    vector<int> neg_locs;

    int other_value = INT_MIN;

    for (int i = start; i <= end; i++) {
      if (input[i] == 0) {
        other_value = max(0, solve(i + 1, end, input));
        end = i - 1;
        break;
      } else if (input[i] < 0) {
        neg_locs.push_back(i);
      }
    }

    if (neg_locs.size() % 2 == 0) {
      // everything can be included.
      int total = INT_MIN;
      for (int i = start; i <= end; i++) {
        if (total != INT_MIN)
          total *= input[i];
        else
          total = input[i];
      }
      return max(total, other_value);
    } else {
      if (neg_locs.size() == 1) {
        int pre = INT_MIN;
        for (int i = start; i < *neg_locs.begin(); i++) {
          if (pre != INT_MIN)
            pre *= input[i];
          else
            pre = input[i];
        }

        int post = INT_MIN;
        for (int i = (*neg_locs.begin()) + 1; i <= end; i++) {
          if (post != INT_MIN)
            post *= input[i];
          else
            post = input[i];
        }

        return max({pre, post, other_value, input[*neg_locs.begin()]});
      } else {
        int mid_value = 1;
        for (int i = (*neg_locs.begin() + 1); i < *neg_locs.rbegin(); i++)
          mid_value *= input[i];

        int pre = mid_value;
        for (int i = start; i <= *neg_locs.begin(); i++)
          pre *= input[i];

        int post = mid_value;
        for (int i = end; i >= *neg_locs.rbegin(); i--)
          post *= input[i];

        return max({pre, post, other_value});
      }
    }
  }

  int maxProduct(vector<int>& input) {
    int answer = solve(0, input.size() - 1, input);
    return answer == INT_MIN ? 0 : answer;
  }
};
