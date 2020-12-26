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

https
    :  // leetcode.com/problems/minimum-initial-energy-to-finish-tasks/submissions/

       // typedef long long int llint;
       typedef long double ldouble;

class Solution {
 public:
  int __calc__(std::vector<std::vector<int>>& values) {
    std::sort(values.begin(), values.end(),
              [](const std::vector<int>& a, const std::vector<int>& b) {
                const int t1 = (a[1] - a[0]);
                const int t2 = (b[1] - b[0]);
                if (t1 == t2)
                  return a[1] > b[1];
                else
                  return t1 > t2;
              });
    int starting_value = 0;
    for (const std::vector<int> i : values)
      starting_value += i[0];
    int bkup = starting_value, adds = 0;
    for (const std::vector<int> i : values) {
      if (bkup >= i[1]) {
        bkup -= i[0];
      } else {
        adds += (i[1] - bkup);
        bkup = i[1] - i[0];
      }
    }
    return starting_value + adds;
  }
};

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> values(n, std::vector<int>(2));
  for (int i = 0; i < n; i++) {
    std::cin >> values[i][0] >> values[i][1];
  }
  Solution temp;
  int answer = temp.__calc__(values);
  std::cout << "Answer : " << answer << std::endl;
  return 0;
}
