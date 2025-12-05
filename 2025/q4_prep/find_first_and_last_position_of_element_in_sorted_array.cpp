class Solution {
 public:
  optional<pair<int, int>> find(int target,
                                int i,
                                int j,
                                const vector<int>& input) {
    if (i > j)
      return nullopt;

    int mid = (i + j) / 2;
    if (input[mid] == target) {
      optional<pair<int, int>> left = find(target, i, mid - 1, input);
      optional<pair<int, int>> right = find(target, mid + 1, j, input);

      pair<int, int> answer = {mid, mid};
      if (left)
        answer.first = min(left->first, mid);
      if (right)
        answer.second = max(right->second, mid);

      return answer;
    } else if (input[mid] < target) {
      return find(target, mid + 1, j, input);
    } else {
      return find(target, i, mid - 1, input);
    }
  }

  vector<int> searchRange(vector<int>& input, int target) {
    optional<pair<int, int>> answer = find(target, 0, input.size() - 1, input);
    if (answer.has_value())
      return {answer->first, answer->second};
    else
      return {-1, -1};
  }
};
