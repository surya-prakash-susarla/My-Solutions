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
typedef std::pair<llint, llint> pint;

#define minval std::numeric_limits<llint>::min()
#define maxval std::numeric_limits<llint>::max()
#define invalid pint({minval, minval})

struct info final {
  llint rows;
  llint cols;
  llint sq_size;
  info() = default;
  info(const llint r, const llint c, const llint g)
      : rows(r), cols(c), sq_size(g) {}
};

const info invalid_info(minval, minval, minval);

inline bool __is_invalid__(const info& a) {
  return a.rows == invalid_info.rows && a.cols == invalid_info.cols &&
         a.sq_size == invalid_info.sq_size;
}

std::tuple<int, pint> __calc__() {
  std::cout << "Enter dimensions" << std::endl;
  llint row, col;
  std::cin >> row >> col;
  std::vector<std::vector<int>> grid(row, std::vector<int>(col));
  std::cout << "Enter values for grid" << std::endl;
  for (llint i = 0; i < row; i++)
    for (llint j = 0; j < col; j++)
      std::cin >> grid[i][j];

  std::vector<std::vector<info>> store(row, std::vector<info>(col));

  llint msize = -1;
  pint location = invalid;

  for (llint i = row - 1; i > -1; i--) {
    for (llint j = col - 1; j > -1; j--) {
      if (grid[i][j] == 1) {
        store[i][j] = invalid_info;
      } else {
        info& current = store[i][j];

        if (j + 1 < col && !__is_invalid__(store[i][j + 1])) {
          current.cols = store[i][j + 1].cols + 1;
        } else {
          current.cols = 1;
        }

        if (i + 1 < row && !__is_invalid__(store[i + 1][j])) {
          current.rows = store[i + 1][j].rows + 1;
        } else {
          current.cols = 1;
        }

        if (i + 1 < row && j + 1 < col &&
            !__is_invalid__(store[i + 1][j + 1])) {
          const llint ts = store[i + 1][j + 1].sq_size + 1;
          current.sq_size = std::min({ts, current.rows, current.cols});
        } else {
          current.sq_size = 1;
        }

        std::cout << "CURRENT LOCATION : " << i << " " << j << std::endl;
        std::cout << "left & right : " << current.rows << " " << current.cols
                  << std::endl;
        std::cout << "grid size : " << current.sq_size << std::endl;

        if (current.sq_size > msize) {
          msize = current.sq_size;
          location.first = i;
          location.second = j;
        }
      }
    }
  }

  return {msize, location};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cout << std::string('-', 20) << std::endl;
  std::cout << "BEGIN" << std::endl;

  const std::tuple<int, pint> answer = __calc__();

  std::cout << std::string('-', 20) << std::endl;
  std::cout << "Max size of grid : " << std::get<0>(answer) << std::endl;
  const pint location = std::get<1>(answer);
  std::cout << "Location : " << location.first << " " << location.second
            << std::endl;

  return 0;
}
