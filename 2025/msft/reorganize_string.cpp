class Solution {
 public:
  string reorganizeString(string input) {
    map<char, int> counts;
    for (char c : input)
      counts[c]++;

    priority_queue<pair<int, char>> values;
    for (auto i : counts)
      values.push({i.second, i.first});

    string answer = "";

    while (not values.empty()) {
      auto current = values.top();
      values.pop();

      if ((not answer.empty() and *answer.rbegin() != current.second) or
          answer.empty()) {
        answer += current.second;
        current.first--;
        if (current.first)
          values.push(current);
      } else {
        if (values.empty())
          return "";
        auto alt = values.top();
        values.pop();
        answer += alt.second;
        alt.first--;
        if (alt.first)
          values.push(alt);
        values.push(current);
      }
    }

    return answer;
  }
};
