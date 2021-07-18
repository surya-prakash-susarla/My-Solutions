#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  vector<int> threeEqualParts(vector<int>& arr) {
#define invalid \
  { -1, -1 }
    typedef vector<int> vint;

    vint ones;
    for (int i = 0; i < arr.size(); i++)
      if (arr[i] == 1)
        ones.push_back(i);

    const size_t size = ones.size();
    if (size == 0)
      return {0, 2};
    else if (size % 3 != 0)
      return invalid;

    // cout << "initial checks passed" << endl;

    const int b_size = size / 3;

    const int trailing_zeros = arr.size() - 1 - *ones.rbegin();

    // cout << "trailing zeros : " << trailing_zeros << endl;

    vint ranges(3);

    int temp = 0;
    int ri = 0;
    for (int i = 0; i < size; i++) {
      temp++;
      if (temp == b_size) {
        ranges[ri++] = ones[i];
        temp = 0;
        if (ri == 3)
          break;
      }
    }

    // cout << "ranges : " << ranges[0] << " " <<  ranges[1] << " " << ranges[2]
    // << endl;

    if (ranges[1] + trailing_zeros >= ranges[2])
      return invalid;
    else if (ranges[0] + trailing_zeros >= ranges[1])
      return invalid;

    vint answer = {ranges[0] + trailing_zeros, ranges[1] + trailing_zeros + 1};

    string first, second, third;

    for (int i = 0; i < arr.size(); i++) {
      if (i <= answer[0])
        first += to_string(arr[i]);
      else if (i < answer[1])
        second += to_string(arr[i]);
      else
        third += to_string(arr[i]);
    }

    auto trim = [](const string a) -> string {
      int ind = 0;
      for (int i = 0; i < a.size(); i++, ind++)
        if (a[i] == '1')
          break;
      return a.substr(ind);
    };

    first = trim(first);
    second = trim(second);
    third = trim(third);

    // cout << "first : " << first << endl;
    // cout << "second : " << second << endl;
    // cout << "third : " << third << endl;

    if (first != second or second != third)
      return invalid;

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
