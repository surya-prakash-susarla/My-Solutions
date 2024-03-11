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
  string customSortString(string values, string input) {
    map<char, int> temp;
    for (char c : input)
      temp[c]++;

    string answer;
    for (char c : values)
      while (temp[c]-- > 0)
        answer += c;

    for (auto i : temp)
      while (i.second-- > 0)
        answer += i.first;

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
