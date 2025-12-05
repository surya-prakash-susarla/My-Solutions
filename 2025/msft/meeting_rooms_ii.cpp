class Solution {
 public:
  int minMeetingRooms(vector<vector<int>>& input) {
    priority_queue<int, vector<int>, greater<int>> values;

    sort(input.begin(), input.end(),
         [](const vector<int>& a, const vector<int>& b) -> bool {
           if (a[0] == b[0])
             return a[1] < b[1];
           return a[0] < b[0];
         });

    int answer = 0;

    for (auto i : input) {
      while (not values.empty() and values.top() <= i[0])
        values.pop();
      values.push(i[1]);
      answer = max(answer, (int)values.size());
    }

    return answer;
  }
};
