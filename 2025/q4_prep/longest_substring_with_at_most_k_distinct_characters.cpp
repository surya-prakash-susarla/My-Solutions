class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string input, int k) {
    map<char, int> counts;

    int l = 0;
    int r = 0;

    int answer = 0;
    while (r < input.size()) {
      counts[input[r]]++;

      while (counts.size() > k) {
        char c = input[l++];
        counts[c]--;
        if (counts[c] == 0)
          counts.erase(c);
      }

      answer = max(answer, (r - l + 1));
      r++;
    }

    return answer;
  }
};
