class Solution {
 public:
  int countBinarySubstrings(string input) {
    vector<int> counts;

    int prev = 1;
    int c = input[0];

    for (int i = 1; i < input.size(); i++) {
      if (input[i] == c) {
        prev++;
      } else {
        counts.push_back(prev);
        prev = 1;
        c = input[i];
      }
    }

    counts.push_back(prev);

    int answer = 0;

    for (int i = 1; i < counts.size(); i++) {
      answer += min(counts[i], counts[i - 1]);
    }

    return answer;
  }
};
