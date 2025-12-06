class Solution {
 public:
  vector<int> intersection(vector<int>& source, vector<int>& target) {
    set<int> values(source.begin(), source.end());
    set<int> answer;
    for (int i : target)
      if (values.contains(i))
        answer.insert(i);
    return vector<int>(answer.begin(), answer.end());
  }
};
