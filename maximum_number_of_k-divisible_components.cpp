class Solution {
 public:
  int maxKDivisibleComponents(int n,
                              vector<vector<int>>& input,
                              vector<int>& orig_values,
                              int k) {
    if (input.size() == 0)
      return 1;
    vector<vector<int>> cons(n);
    vector<int> sizes(n, 0);
    vector<bool> used(n, false);

    vector<long long> values(orig_values.begin(), orig_values.end());

    for (auto i : input) {
      cons[i[0]].push_back(i[1]);
      sizes[i[0]]++;
      cons[i[1]].push_back(i[0]);
      sizes[i[1]]++;
    }

    queue<int> current;
    for (int i = 0; i < n; i++)
      if (sizes[i] == 1)
        current.push(i);

    int answer = 0;
    while (not current.empty()) {
      int node = current.front();
      current.pop();

      used[node] = true;

      int parent;
      for (auto i : cons[node])
        if (not used[i]) {
          parent = i;
          break;
        }

      if (values[node] % k == 0) {
        // the current component is divisible.
        answer++;
      } else {
        // merge with parent.
        values[parent] += values[node];
      }

      // remove connection and add node if appropriate.
      sizes[node] = 0;
      sizes[parent]--;

      if (sizes[parent] == 1)
        current.push(parent);
    }

    return answer;
  }
};
