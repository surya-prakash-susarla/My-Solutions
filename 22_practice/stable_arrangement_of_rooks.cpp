#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

#define in scanf
#define out printf

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

typedef vector<char> vchar;
typedef vector<vchar> vvchar;

std::optional<vvchar> __calc__() {
  llint n, k;
  cin >> n >> k;

  if (n < (k * 2) - 1)
    return std::nullopt;

  constexpr char EMPTY = '.';
  constexpr char ROOK = 'R';

  vvchar answer = vvchar(n, vchar(n, EMPTY));

  for (int _ = 0, i = 0, j = 0; _ < k && i < n; _++, i += 2, j += 2)
    answer[i][j] = ROOK;

  return answer;
}

void __print__(const vvchar& input) {
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[i].size(); j++) {
      cout << input[i][j];
      // if ( j < input[i].size()-1 )  cout << " " ;
    }
    if (i < input.size() - 1)
      cout << endl;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  llint t;
  cin >> t;

  for (llint i = 0; i < t; i++) {
    std::optional<vvchar> answer = __calc__();
    if (answer == std::nullopt) {
      cout << "-1";
    } else {
      __print__(answer.value());
    }
    if (i < t - 1)
      cout << endl;
  }

  return 0;
}
