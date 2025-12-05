class Solution {
 public:
  vector<int> processQueries(int c,
                             vector<vector<int>>& connections,
                             vector<vector<int>>& queries) {
    vector<int> parent(c + 1, -1);

    unordered_map<int, int> sizes;

    function<int(int)> get_parent = [&](const int i) -> int {
      if (parent[i] == -1)
        return i;

      return parent[i] = get_parent(parent[i]);
    };

    function<void(int a, int b)> merge = [&](const int a, const int b) -> void {
      int parent_a = get_parent(a);
      int parent_b = get_parent(b);

      if (parent_a != parent_b) {
        int& sa = sizes[parent_a];
        int& sb = sizes[parent_b];

        if (sa > sb) {
          sa += sb;
          sb = 0;

          parent[parent_b] = parent_a;
        } else {
          sb += sa;
          sa = 0;

          parent[parent_a] = parent_b;
        }
      }
    };

    for (auto i : connections)
      merge(i[0], i[1]);

    vector<bool> status(c + 1, true);

    vector<int> answer;

    // unordered_map<int, int> pm;

    // // optimize parent finding with map cause now everything is immutable.
    // function<int(int)> gp = [&](const int i) -> int {
    //     if ( pm.contains(i) )
    //         return pm[i];

    //     int val;
    //     if ( parent[i] == -1 ) {
    //         val = i;
    //     } else {
    //         val = gp(parent[i]);
    //     }
    //     pm[i] = val;
    //     return val;
    // };

    unordered_map<int, set<int>> plocs;
    for (int i = 1; i <= c; i++) {
      plocs[get_parent(i)].insert(i);
    }

    for (auto i : queries) {
      if (i[0] == 2) {
        status[i[1]] = false;
        plocs[get_parent(i[1])].erase(i[1]);
      } else {
        if (status[i[1]]) {
          answer.push_back(i[1]);
        } else {
          int rp = get_parent(i[1]);
          if (plocs[rp].empty())
            answer.push_back(-1);
          else
            answer.push_back(*plocs[rp].begin());
        }
      }
    }

    return answer;
  }
};
