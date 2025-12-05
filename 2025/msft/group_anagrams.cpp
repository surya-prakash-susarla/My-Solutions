class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& input) {
    map<string, vector<string>> values;
    for (const string& i : input) {
      string temp = i;
      sort(temp.begin(), temp.end());
      values[temp].push_back(i);
    }
    vector<vector<string>> answer;
    for (auto i : values)
      answer.push_back(i.second);
    return answer;
  }
};
