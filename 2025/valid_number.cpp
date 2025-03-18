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
  inline bool is_num(char c) { return '0' <= c and c <= '9'; }

  inline bool is_e(char c) { return c == 'e' or c == 'E'; }

  inline bool is_sym(char c) { return c == '+' or c == '-'; }

  inline bool is_digits(const string& s, int start, int end) {
    for (int i = start; i <= end; i++)
      if (not is_num(s[i]))
        return false;
    return true;
  }

  bool is_integer(const string& s, int start, int end) {
    bool is_sym_found = false;
    if (is_sym(s[start])) {
      start++;
      is_sym_found = true;
    }

    if (is_sym_found) {
      return (end - start >= 0) and is_digits(s, start, end);
    } else {
      return is_digits(s, start, end);
    }
  }

  bool check_number(const string& s,
                    int start,
                    int end,
                    bool is_valid_e_available) {
    int dot_ind = -1;
    for (int i = start; i <= end; i++)
      if (s[i] == '.') {
        if (dot_ind != -1)
          return false;
        dot_ind = i;
      }

    if (dot_ind == 0) {
      bool is_valid_suffix = (end - dot_ind > 0);
      return is_digits(s, dot_ind + 1, end) and is_valid_suffix;
    } else if (dot_ind != -1) {
      bool is_valid_suffix = is_valid_e_available or (end - dot_ind > 0);
      bool is_valid_prefix = (dot_ind - start > 0);
      bool is_sym_only_prefix = (dot_ind - start == 1 and is_sym(s[start]));
      bool prefix_valid =
          is_sym_only_prefix or is_integer(s, start, dot_ind - 1);

      if (is_sym_only_prefix) {
        if (not is_valid_suffix)
          return false;

        if (end - dot_ind <= 0)
          return false;
      }

      return prefix_valid and is_digits(s, dot_ind + 1, end) and
             (is_valid_suffix or is_valid_prefix);
    } else {
      return is_integer(s, start, end);
    }
  }

  bool isNumber(string s) {
    int e_ind = -1;
    for (int i = 0; i < s.size(); i++) {
      if (is_e(s[i])) {
        if (e_ind != -1)
          return false;
        e_ind = i;
      }
    }

    if (e_ind == -1) {
      return check_number(s, 0, s.size() - 1, false);
    } else {
      int e_start = e_ind + 1;
      int e_end = s.size() - 1;
      if (s.size() - e_start < 1 or not is_integer(s, e_start, e_end))
        return false;
      bool is_valid_prefix = (e_ind > 0);
      return check_number(s, 0, e_ind - 1, true) and is_valid_prefix;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
