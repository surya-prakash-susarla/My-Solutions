class Solution {
 public:
  int intersectionSizeTwo(vector<vector<int>>& intervals) {
    vector<int> answer;

    sort(intervals.begin(), intervals.end(),
         [](const vector<int>& a, const vector<int>& b) {
           if (a[1] == b[1])
             return b[0] < a[0];
           return a[1] < b[1];
         });

    auto get_coverage_count = [&](const vector<int>& ref) {
      int count = 0;
      if (answer.empty())
        return 0;
      for (int i = answer.size() - 1; i > (int)answer.size() - 3; i--) {
        if (ref[0] <= answer[i] and ref[1] >= answer[i])
          count++;
        else
          break;
      }
      return count;
    };

    for (int i = 0; i < intervals.size(); i++) {
      int count = get_coverage_count(intervals[i]);

      if (count == 2) {
        // fully covered, so skip
        continue;
      } else if (count == 1) {
        // needs an insertion, so pick the end
        answer.push_back(intervals[i][1]);
      } else {
        answer.push_back(intervals[i][1] - 1);
        answer.push_back(intervals[i][1]);
      }
    }

    return answer.size();
  }
};
