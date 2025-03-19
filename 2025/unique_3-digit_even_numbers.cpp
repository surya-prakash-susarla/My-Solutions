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
  int totalNumbers(vector<int>& input) {
    map<int, int> counter;
    for (int i : input)
      counter[i]++;

    int answer = 0;

    for (auto i : counter) {
      if (i.first % 2 == 0) {
        counter[i.first]--;

        for (auto j : counter) {
          if (j.second) {
            counter[j.first]--;
            int third = 0;
            for (auto k : counter)
              if (k.first != 0 and k.second)
                third++;
            answer += third;
            counter[j.first]++;
          }
        }

        counter[i.first]++;
      }
    }

    return answer;
  }
};
©leetcode

    int
    main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
