class Solution {
 public:
  int countPalindromicSubsequence(string input) {
    typedef vector<int> vint;
    typedef vector<vint> vvint;

    vvint values(26);

    auto ind = [](const char& a) { return a - 'a'; };

    for (int i = 0; i < input.size(); i++) {
      values[ind(input[i])].push_back(i);
    }

    int answer = 0;

    for (int i = 0; i < 26; i++) {
      if (values[i].size() > 2)
        answer++;

      if (values[i].size() < 2) {
        continue;
      }

      for (int j = 0; j < 26; j++) {
        if (i != j and values[j].size() != 0) {
          auto it = lower_bound(values[j].begin(), values[j].end(),
                                *values[i].rbegin());
          if (it == values[j].end()) {
            if (*values[j].rbegin() > *values[i].begin()) {
              answer++;
            }
          } else if (it != values[j].begin()) {
            auto it2 = prev(it);
            if (*it2 > *values[i].begin())
              answer++;
          }
        }
      }
    }

    return answer;
  }
};
