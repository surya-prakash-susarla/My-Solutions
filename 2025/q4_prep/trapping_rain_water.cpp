class Solution {
 public:
  int trap(vector<int>& input) {
    const int n = input.size();
    vector<pair<int, int>> values(n);
    values[n - 1] = {0, 0};

    for (int i = n - 2; i > -1; i--) {
      pair<int, int> temp = {input[i + 1], i + 1};
      if (values[i + 1].first >= temp.first) {
        temp.first = values[i + 1].first;
        temp.second = values[i + 1].second;
      }
      values[i] = temp;
    }

    int answer = 0;
    for (int i = 0; i < n;) {
      pair<int, int> b = values[i];
      int limit = min(input[i], b.first);
      int j;
      int current = 0;
      for (j = i + 1; j < b.second; j++) {
        if (input[j] > limit) {
          break;
        }
        current += (limit - input[j]);
      }
      i = j;
      answer += current;
    }

    return answer;
  }
};
