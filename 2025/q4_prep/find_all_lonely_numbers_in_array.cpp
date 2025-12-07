class Solution {
 public:
  vector<int> findLonely(vector<int>& input) {
    unordered_map<int, int> counts;
    for (int i : input)
      counts[i]++;

    vector<int> answer;

    for (auto i : counts) {
      if (i.second == 1 and not counts.contains(i.first - 1) and
          not counts.contains(i.first + 1))
        answer.push_back(i.first);
    }

    return answer;
  }
};
