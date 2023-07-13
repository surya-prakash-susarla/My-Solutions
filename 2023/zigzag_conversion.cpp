#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Solution {
 public:
  string convert(string values, int n) {
    typedef vector<char> vc;
    typedef vector<vc> vvc;

    const int cols_per_set = n - 1;
    const int letters_per_set = 2 * cols_per_set;

    // cout << "values size : " << values.size() << endl;
    // cout << "letters per set : " << letters_per_set << endl;

    if (letters_per_set == 0) {
      return values;
    }

    const auto sets = ceil((double)values.size() / letters_per_set);

    vvc temp(n, vc(sets * cols_per_set, '@'));

    int main_index = 0;
    int base_col = 0;
    while (main_index < values.size()) {
      for (int i = 0; i < n; i++) {
        temp[i][base_col] = values[main_index++];
        if (main_index >= values.size())
          break;
      }

      if (main_index >= values.size())
        break;

      for (int i = 1; i < cols_per_set; i++) {
        temp[n - 1 - i][base_col + i] = values[main_index++];
        if (main_index >= values.size())
          break;
      }

      base_col += cols_per_set;
    }

    string answer;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < sets * cols_per_set; j++) {
        if (temp[i][j] != '@')
          answer += temp[i][j];
      }
    }

    // cout << "size of origina value : " << values.size() << endl;
    // cout << "size of answer : " << answer.size() << endl;

    // cout << "contents of answer : " << endl;
    // for ( char i : answer ) cout << "@" << i << "@" << " " ;
    // cout << endl;

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
