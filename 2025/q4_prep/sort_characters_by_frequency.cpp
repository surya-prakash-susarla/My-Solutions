class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<char, int> counts;
    for (char c : s)
      counts[c]++;

    map<int, vector<char>> inverted;
    for (auto i : counts)
      inverted[i.second].push_back(i.first);

    string answer;

    for_each(inverted.rbegin(), inverted.rend(),
             [&](const pair<int, vector<char>>& i) {
               for (char j : i.second)
                 answer += string(i.first, j);
             });

    return answer;
  }
};
