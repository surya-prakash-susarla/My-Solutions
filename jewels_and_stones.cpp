class Solution {
 public:
  int numJewelsInStones(string input, string values) {
    set<char> allowed;
    for (char c : input)
      allowed.insert(c);
    int answer = 0;
    for (char c : values)
      if (allowed.find(c) != allowed.end())
        answer++;
    return answer;
  }
};