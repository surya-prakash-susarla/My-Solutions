class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& input, vector<int>& req) {
    input.push_back(req);
    sort(input.begin(), input.end(),
         [](const vector<int>& a, const vector<int>& b) {
           if (a[0] == b[0])
             return a[1] < b[1];
           return a[0] < b[0];
         });

    auto is_overlap = [&](const vector<int>& a, const vector<int>& b) {
      if (b[0] <= a[1])
        return true;
      return false;
    };

    auto merge = [&](const vector<int>& a,
                     const vector<int>& b) -> vector<int> {
      return {min(a[0], b[0]), max(a[1], b[1])};
    };

    stack<vector<int>> values;
    for (auto i : input) {
      if (values.empty()) {
        values.push(i);
      } else {
        vector<int> temp = values.top();
        if (is_overlap(temp, i)) {
          values.pop();
          vector<int> result = merge(temp, i);
          values.push(result);
        } else {
          values.push(i);
        }
      }
    }

    vector<vector<int>> answer;
    for (; not values.empty(); values.pop())
      answer.push_back(values.top());

    reverse(answer.begin(), answer.end());

    return answer;
  }
};
