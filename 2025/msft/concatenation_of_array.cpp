class Solution {
 public:
  vector<int> getConcatenation(vector<int>& input) {
    input.insert(input.end(), input.begin(), input.end());
    return input;
  }
};
