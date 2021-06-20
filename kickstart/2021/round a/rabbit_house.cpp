#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <stack>
#include <utility>
#include <vector>

#define in scanf
#define out printf

// Problem:

typedef long long int llint;
typedef long double ldouble;
typedef std::pair<llint, llint> pint;

llint __calc__() {
  llint row, col;
  std::cin >> row >> col;

  std::vector<std::vector<llint>> grid(row, std::vector<llint>(col));

  std::map<llint, std::set<pint>> height_store;

  for (llint i = 0; i < row; i++)
    for (llint j = 0; j < col; j++) {
      std::cin >> grid[i][j];
      height_store[grid[i][j]].insert({i, j});
    }

  llint answer = 0;
  for (auto it = height_store.rbegin(); it != height_store.rend(); it++) {
    const std::set<pint>& target_locations = it->second;
    const llint& current_height = it->first;

    for (const pint& i : target_locations) {
      const llint& x = i.first;
      const llint& y = i.second;

      // validate if grid height matches the height indicated here
      if (grid[x][y] != current_height)
        continue;

      auto update = [&grid, &height_store, &answer](
                        const llint& x, const llint& y,
                        const llint& parent_height) {
        if (grid[x][y] >= parent_height)
          return;

        if (parent_height - grid[x][y] > 1) {
          answer += (parent_height - 1 - grid[x][y]);
          grid[x][y] = parent_height - 1;
          height_store[parent_height - 1].insert({x, y});
        }
      };

      // top
      if (x - 1 > -1)
        update(x - 1, y, current_height);
      // bottom
      if (x + 1 < row)
        update(x + 1, y, current_height);
      // left
      if (y - 1 > -1)
        update(x, y - 1, current_height);
      // right
      if (y + 1 < col)
        update(x, y + 1, current_height);
    }
  }

  return answer;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  llint t;
  std::cin >> t;
  for (llint i = 1; i <= t; i++) {
    llint answer = __calc__();
    std::cout << "Case #" << i << ": " << answer << std::endl;
  }

  return 0;
}
