class Solution {
 public:
  vector<bool> prefixesDivBy5(vector<int>& input) {
    unsigned long long current = 0;

    vector<bool> answer;

    for (int i : input) {
      current *= 2;
      current += (i);
      answer.push_back((current % 5 == 0));
      current %= 5;
    }

    return answer;
  }
};
