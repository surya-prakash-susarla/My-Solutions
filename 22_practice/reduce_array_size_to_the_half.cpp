#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minSetSize(vector<int>& values) {
    map<int, int> freq;
    for (int i : values)
      freq[i]++;

    typedef pair<int, int> pint;

    priority_queue<pint> temp;
    for (const pint& i : freq)
      temp.push({i.second, i.first});

    int answer = 0;
    int current_size = 0;
    int target = values.size() / 2;

    while (not temp.empty()) {
      current_size += temp.top().first;
      answer++;
      if (current_size >= target)
        break;
      temp.pop();
    }

    return answer;
  }
};
