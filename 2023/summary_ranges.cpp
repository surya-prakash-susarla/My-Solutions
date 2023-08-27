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
  vector<string> summaryRanges(vector<int>& values) {
    if (values.empty())
      return {};

    vector<string> answer;
    int begin = values[0];
    int end = values[0];

    for (int i = 1; i < values.size(); i++) {
      if (values[i] == end + 1) {
        end = values[i];
      } else {
        if (begin == end)
          answer.emplace_back(to_string(begin));
        else
          answer.emplace_back(to_string(begin) + "->" + to_string(end));

        begin = values[i];
        end = values[i];
      }
    }

    if (begin == end)
      answer.emplace_back(to_string(begin));
    else
      answer.emplace_back(to_string(begin) + "->" + to_string(end));

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
