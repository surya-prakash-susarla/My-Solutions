#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <stack>
#include <utility>
#include <vector>

#define in scanf
#define out printf

// Problem:

typedef long long int llint;
typedef long double ldouble;

struct dets final {
  llint up = 0;
  llint down = 0;
  llint left = 0;
  llint right = 0;
};

llint __calc__() {
  llint r, c;
  std::cin >> r >> c;

  std::vector<std::vector<int>> input(r, std::vector<int>(c));
  for (llint i = 0; i < r; i++)
    for (llint j = 0; j < c; j++)
      std::cin >> input[i][j];

  std::vector<std::vector<dets>> values(r, std::vector<dets>(c));

  // height up calc;
  for (llint j = 0; j < c; j++)
    for (llint i = 0; i < r; i++) {
      if (input[i][j] == 0)
        values[i][j].up = 0;
      else
        values[i][j].up = i == 0 ? 1 : (values[i - 1][j].up + 1);
    }

  // height down calculation;
  for (llint j = 0; j < c; j++)
    for (llint i = r - 1; i > -1; i--) {
      if (i == r - 1)
        values[i][j].down = input[i][j];
      else
        values[i][j].down = input[i][j] == 0 ? 0 : values[i + 1][j].down + 1;
    }

  // width left calculation;
  for (llint i = 0; i < r; i++)
    for (llint j = 0; j < c; j++) {
      if (j == 0)
        values[i][j].left = input[i][j];
      else
        values[i][j].left = input[i][j] == 0 ? 0 : values[i][j - 1].left + 1;
    }

  // width right calculation;
  for (llint i = 0; i < r; i++)
    for (llint j = c - 1; j > -1; j--) {
      if (j == c - 1)
        values[i][j].right = input[i][j];
      else
        values[i][j].right = input[i][j] == 0 ? 0 : values[i][j + 1].right + 1;
    }

  // traverse and do final L identifications
  llint answer = 0;
  for (llint i = 0; i < r; i++) {
    for (llint j = 0; j < c; j++) {
      dets current = values[i][j];

      if (input[i][j] == 0)
        continue;

      if ((current.left == 1 and current.right == 1) ||
          (current.up == 1 and current.down == 1)) {
        continue;
      }

      const llint l = current.left, r = current.right, h = current.up,
                  d = current.down;

      auto test = [&](const llint& a, const llint& b) -> void {
        for (llint i = 2, j = 4; i <= a and j <= b; i++, j = i * 2)
          answer++;
      };

      test(l, h);
      test(l, d);
      test(r, h);
      test(r, d);
      test(h, l);
      test(h, r);
      test(d, l);
      test(d, r);
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
    std::cout << "Case #" << i << ": " << answer << "\n";
  }

  return 0;
}
