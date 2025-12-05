class Solution {
 public:
  int lengthOfLongestSubstring(string input) {
    unordered_map<char, bool> used;

    int left = 0;
    int right = 0;

    int answer = 0;

    while (right < input.size()) {
      if (used[input[right]]) {
        answer = max(answer, right - left);
        while (used[input[right]] and left != right) {
          used[input[left++]] = false;
        }
      }
      used[input[right]] = true;
      right++;
    }

    answer = max(answer, (int)input.size() - left);
    return answer;
  }
};
