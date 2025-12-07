class Solution {
 public:
  class dsu {
   public:
    dsu(int n) : parent(n, -1), rank(n, 0), comps(n) {}

    int get(int x) { return parent[x] == -1 ? x : parent[x] = get(parent[x]); }

    void unite(int x, int y) {
      int p1 = get(x);
      int p2 = get(y);
      if (p1 == p2)
        return;
      comps--;
      if (rank[p1] > rank[p2]) {
        parent[p2] = p1;
        rank[p1]++;
      } else {
        parent[p1] = p2;
        rank[p2]++;
      }
    }

    int count() { return comps; }

   private:
    vector<int> parent;
    vector<int> rank;
    int comps;
  };

  int minCost(int n, vector<vector<int>>& edges, int k) {
    sort(edges.begin(), edges.end(),
         [](const vector<int>& a, const vector<int>& b) -> bool {
           if (a[2] == b[2])
             return a[1] < b[1];
           return a[2] < b[2];
         });

    if (edges.empty()) {
      return 0;
    }

    int l = 0;
    int r = edges.back()[2];

    int answer = INT_MAX;
    while (l <= r) {
      int mid = (l + r) / 2;

      dsu temp(n);
      for (auto i : edges) {
        if (i[2] <= mid) {
          temp.unite(i[0], i[1]);
        } else {
          break;
        }
      }

      if (temp.count() <= k) {
        answer = min(answer, mid);
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return answer;
  }
};
