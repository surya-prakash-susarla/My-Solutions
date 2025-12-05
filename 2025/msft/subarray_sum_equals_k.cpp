class Solution {
 public:
  int subarraySum(vector<int>& input, int k) {
    map<int, int> prefixes;
    prefixes[0] = 1;
    int current = 0;
    int answer = 0;

    for (int i : input) {
      current += i;
      answer += prefixes[current - k];
      prefixes[current]++;
    }

    return answer;
  }
};
