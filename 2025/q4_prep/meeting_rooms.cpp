class Solution {
 public:
  bool canAttendMeetings(vector<vector<int>>& input) {
    sort(input.begin(), input.end(),
         [](const vector<int>& a, const vector<int>& b) {
           if (a[1] == b[1])
             return a[0] < b[0];
           return a[1] < b[1];
         });

    for (int i = 1; i < input.size(); i++) {
      if (input[i][0] < input[i - 1][1])
        return false;
    }
    return true;
  }
};
