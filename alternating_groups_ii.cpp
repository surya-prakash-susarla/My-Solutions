class Solution {
 public:
  int numberOfAlternatingGroups(vector<int>& input, int k) {
    int prev_count = 1;

    vector<int> values;

    for (int i = 1; i < input.size(); i++) {
      if (input[i] != input[i - 1]) {
        prev_count++;
      } else {
        values.push_back(prev_count);
        values.push_back(INT_MAX);
        prev_count = 1;
      }
    }
    values.push_back(prev_count);

    if (values.size() > 1 and *values.begin() != INT_MAX and
        *values.rbegin() != INT_MAX and input[0] != input[input.size() - 1]) {
      values[0] = values[0] + *values.rbegin();
      values.erase(prev(values.end()));
    }

    if (values.size() == 1) {
      if (*input.begin() != *input.rbegin())
        return values[0];
      else
        return (values[0] - k + 1);
    }

    int answer = 0;

    for (int i : values) {
      if (i != INT_MAX and i >= k) {
        answer += (i - k + 1);
      }
    }

    return answer;
  }
};
