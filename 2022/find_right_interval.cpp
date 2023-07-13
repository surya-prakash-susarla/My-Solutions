class Solution {
 public:
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    typedef vector<int> vint;

    map<int, int> keys;
    for (int i = 0; i < intervals.size(); i++)
      keys[intervals[i][0]] = i;

    vint answer;
    for (int i = 0; i < intervals.size(); i++) {
      map<int, int>::iterator it = keys.lower_bound(intervals[i][1]);
      if (it == keys.end())
        answer.push_back(-1);
      else
        answer.push_back(it->second);
    }

    return answer;
  }
};
