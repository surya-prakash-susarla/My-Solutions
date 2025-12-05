class Solution {
 public:
  vector<int> findOrder(int n, vector<vector<int>>& requirement) {
    vector<vector<int>> deps(n);
    vector<int> deg(n, 0);

    for (auto i : requirement) {
      deps[i[1]].push_back(i[0]);
      deg[i[0]]++;
    }

    queue<int> current;
    for (int i = 0; i < n; i++)
      if (deg[i] == 0)
        current.push(i);

    int covered_count = 0;
    vector<int> answer;
    while (not current.empty()) {
      queue<int> next;
      for (auto i = current.front(); not current.empty();
           current.pop(), i = current.front()) {
        deg[i] = INT_MIN;
        covered_count++;
        answer.push_back(i);
        for (auto j : deps[i]) {
          deg[j]--;
          if (deg[j] == 0) {
            next.push(j);
          }
        }
      }
      if (covered_count == n)
        break;
      if (next.empty())
        return {};
      swap(current, next);
    }

    return answer;
  }
};
