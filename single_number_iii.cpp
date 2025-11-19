class Solution {
 public:
  vector<int> singleNumber(vector<int>& input) {
    unordered_set<int> values;

    for (int i : input) {
      if (values.find(i) != values.end()) {
        values.erase(i);
      } else {
        values.insert(i);
      }
    }

    return vector<int>(values.begin(), values.end());
  }
};
