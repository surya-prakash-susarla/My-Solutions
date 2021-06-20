class Solution {
 public:
  pair<int, int> findLargest(const vector<int>& input, int limit) {
    pair<int, int> answer;
    answer.first = -1;
    answer.second = -1;
    for (int i = 0; i <= limit; i++)
      if (input[i] > answer.first)
        answer.first = input[i], answer.second = i;
    return answer;
  }

  vector<int> pancakeSort(vector<int>& input) {
    vector<int> sorted(input);
    sort(sorted.begin(), sorted.end());

    vector<int> answer;

    for (int i = input.size() - 1; i > 0; i--) {
      if (input == sorted)
        break;

      pair<int, int> max_value = findLargest(input, i);
      auto end = input.begin() + max_value.second + 1 > input.end()
                     ? input.end()
                     : input.begin() + max_value.second + 1;
      reverse(input.begin(), end);
      auto part = input.begin() + i + 1 > input.end() ? input.end()
                                                      : input.begin() + i + 1;
      reverse(input.begin(), part);

      answer.push_back(max_value.second + 1);
      answer.push_back(i + 1);
    }
    return answer;
  }
};