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
  vector<vector<int>> employeeFreeTime(vector<vector<vector<int>>> schedule) {
    vector<vector<int>> input;
    for (auto i : schedule)
      input.insert(input.end(), i.begin(), i.end());
    sort(input.begin(), input.end());

    vector<int> current = input[0];
    vector<vector<int>> values;
    for (int i = 1; i < input.size(); i++) {
      if (input[i][0] <= current[1]) {
        current[1] = max(current[1], input[i][1]);
      } else {
        values.push_back(current);
        current = input[i];
      }
    }
    values.push_back(current);

    vector<vector<int>> answer;
    int start = 1;

    for (auto i : values) {
      int end = i[0];
      if (end > start)
        answer.push_back({start, end});
      start = i[1];
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
