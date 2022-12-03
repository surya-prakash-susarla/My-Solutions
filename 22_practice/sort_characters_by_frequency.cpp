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
  string frequencySort(string input) {
    map<char, int> values;
    for (char c : input)
      values[c]++;
    priority_queue<pair<int, char>> temp;
    for (const pair<char, int>& i : values)
      temp.push({i.second, i.first});

    string answer;

    while (not temp.empty()) {
      pair<int, char> temp2 = temp.top();
      answer = answer + string(temp2.first, temp2.second);
      temp.pop();
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
