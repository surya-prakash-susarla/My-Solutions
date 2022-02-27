#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  inline int getMostRepeatedCount(const unordered_map<char, int> values) {
    auto it =
        max_element(values.begin(), values.end(),
                    [](const pair<char, int>& a, const pair<char, int>& b) {
                      return a.second < b.second;
                    });
    if (it == values.end())
      cout << "THIS SHOULD NEVER HAPPEN" << endl;

    return it->second;
  }

  int characterReplacement(string input, int k) {
    unordered_map<char, int> values;
    int answer = 0;

    int lindex = 0;
    for (int i = 0; i < input.size(); i++) {
      values[input[i]]++;

      int most_repeated_char_count = getMostRepeatedCount(values);

      while ((i - lindex + 1) - most_repeated_char_count > k) {
        values[input[lindex++]]--;
      }

      answer = max(answer, i - lindex + 1);
    }

    return answer;
  }
};