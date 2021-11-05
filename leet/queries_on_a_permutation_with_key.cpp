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
  vector<int> processQueries(vector<int>& input, int m) {
    map<int, int> values;
    for (int i = 0; i < m; i++)
      values[i + 1] = i;

    vector<int> answer;

    for (const int& i : input) {
      int cindex = values[i];
      answer.push_back(cindex);

      for (map<int, int>::iterator it = values.begin(); it != values.end();
           it++)
        if (it->second < cindex)
          it->second++;

      values[i] = 0;
    }

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
