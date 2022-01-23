#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid,
                                          vector<int>& pricing,
                                          vector<int>& start,
                                          int k) {
    const int rsize = grid.size();
    const int csize = grid[0].size();
    vector<vector<bool>> visited(rsize, vector<bool>(csize, false));

    // x , y , dist
    typedef tuple<int, int, int> loc_type;
    queue<loc_type> locs;
    locs.push(make_tuple(start[0], start[1], 0));

    struct item_comp {
      // x , y , cost , dist
      bool operator()(const vector<int>& a, const vector<int>& b) {
        if (a[3] != b[3])
          return a[3] > b[3];
        else {
          if (a[2] != b[2])
            return a[2] > b[2];
          else {
            if (a[0] != b[0])
              return a[0] > b[0];
            else {
              if (a[1] != b[1])
                return a[1] > b[1];
              return false;
            }
          }
        }
      }
    };

    priority_queue<vector<int>, vector<vector<int>>, item_comp> shortlist;
    int max_dist_in_shortlist = 0;

    while (!locs.empty()) {
      loc_type current = locs.front();
      locs.pop();

      int x, y, dist;
      tie(x, y, dist) = current;
      const int& current_value = grid[x][y];

      if (current_value == 0 || visited[x][y])
        continue;
      visited[x][y] = true;
      if (current_value >= pricing[0] && current_value <= pricing[1]) {
        if (shortlist.size() >= k and dist > max_dist_in_shortlist) {
          continue;
        } else {
          shortlist.push({x, y, current_value, dist + 1});
          max_dist_in_shortlist = max(max_dist_in_shortlist, dist);
        }
      }

      dist++;
      if (x - 1 > -1)
        locs.push({x - 1, y, dist});
      if (y - 1 > -1)
        locs.push({x, y - 1, dist});
      if (x + 1 < rsize)
        locs.push({x + 1, y, dist});
      if (y + 1 < csize)
        locs.push({x, y + 1, dist});
    }

    vector<vector<int>> answer;
    while (k-- && !shortlist.empty()) {
      const vector<int>& top = shortlist.top();
      answer.push_back({top[0], top[1]});
      shortlist.pop();
    }

    return answer;
  }
};
