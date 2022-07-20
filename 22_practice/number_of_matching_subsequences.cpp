#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int numMatchingSubseq(string input, vector<string>& words) {
    typedef pair<int, int> pint;

    map<char, list<pint>> values;
    for (int i = 0; i < words.size(); i++)
      values[words[i][0]].push_back({i, 0});

    int answer = 0;

    for (char c : input) {
      list<pint>& ref = values[c];
      list<pint>::iterator it = ref.begin();
      while (it != ref.end()) {
        it->second++;
        if (it->second >= words[it->first].size())
          answer++;
        else
          values[words[it->first][it->second]].push_front(*it);
        it = ref.erase(it);
      }
    }

    return answer;
  }
};
