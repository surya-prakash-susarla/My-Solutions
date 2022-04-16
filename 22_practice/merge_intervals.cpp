class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const vector<int>& a, const vector<int>& b) {
           if (a[0] != b[0])
             return a[0] < b[0];
           return a[1] < b[1];
         });

    vector<vector<int>> answer;
    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] <= end) {
        end = max(end, intervals[i][1]);
      } else {
        answer.push_back({start, end});
        start = intervals[i][0];
        end = intervals[i][1];
      }
    }

    answer.push_back({start, end});

    return answer;
  }
};
