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
  vector<int> topKFrequent(vector<int>& values, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>
        sorter;
    map<int, int> counter;
    for (int i : values) {
      counter[i]++;
      sorter.push(make_pair(counter[i], i));
    }

    vector<int> answer;

    while (k > 0) {
      pair<int, int> top = sorter.top();
      sorter.pop();
      if (top.first == counter[top.second]) {
        answer.push_back(top.second);
        k--;
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
