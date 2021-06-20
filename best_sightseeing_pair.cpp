class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& input) {
    vector<pair<int, int>> min_max(input.size());

    min_max[0].first = numeric_limits<int>::min();
    min_max[input.size() - 1].second = numeric_limits<int>::min();

    // left to right fill i values if the index was considered as j value
    int global_max = input[0];
    for (int i = 1; i < input.size(); i++) {
      min_max[i].first = global_max;
      global_max = max(global_max, input[i] + i);
    }

    // right to left fill j values if the index was considered as i value

    // combine final answer loop as well to reduce the time
    int answer = min_max[input.size() - 1].first +
                 (input[input.size() - 1] - (input.size() - 1));

    global_max = input[input.size() - 1] - input.size() - 1;
    for (int i = input.size() - 2; i > -1; i--) {
      min_max[i].second = global_max;
      global_max = max(global_max, input[i] - i);

      // consider the current index as the i value
      answer = max(answer, input[i] + i + min_max[i].second);

      // consider the current index as the j value
      if (i > 0)
        answer = max(answer, min_max[i].first + input[i] - i);
    }

    return answer;
  }
};