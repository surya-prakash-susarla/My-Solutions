class Solution {
 public:
  bool is_between(int target, int a, int b) {
    return target >= a and target <= b;
  }

  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                           vector<vector<int>>& secondList) {
    typedef vector<int> vint;
    typedef vector<vint> vvint;

    if (firstList.empty() or secondList.empty())
      return {};

    vvint answer;
    for (int i = 0, j = 0; i < firstList.size() and j < secondList.size();) {
      const vint& temp1 = firstList[i];
      const vint& temp2 = secondList[j];

      if (is_between(temp1[0], temp2[0], temp2[1]) or
          is_between(temp2[0], temp1[0], temp1[1])) {
        answer.push_back({max(temp1[0], temp2[0]), min(temp1[1], temp2[1])});
      }

      if (temp1[1] < temp2[1])
        i++;
      else if (temp2[1] < temp1[1])
        j++;
      else {
        i++;
        j++;
      }
    }

    return answer;
  }
};
