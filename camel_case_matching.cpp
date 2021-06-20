class Solution {
 public:
  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> answer(queries.size(), true);
    for (int i = 0; i < queries.size(); i++) {
      int index = 0;
      for (char c : queries[i]) {
        if (c >= 'a' and c <= 'z') {
          if (index < pattern.size() and c == pattern[index])
            index += 1;
        } else if (index >= pattern.size() or c != pattern[index]) {
          answer[i] = false;
          break;
        } else
          index += 1;
      }
      if (index != pattern.size())
        answer[i] = false;
    }
    return answer;
  }
};