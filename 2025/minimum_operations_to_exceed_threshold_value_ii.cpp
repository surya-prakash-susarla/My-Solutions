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
  int minOperations(vector<int>& input, int k) {
    typedef long long int llint;

    priority_queue<llint, vector<llint>, greater<llint>> store;
    for (int i : input)
      store.push(i);

    int answer = 0;
    while (store.size() > 1) {
      if (store.top() >= k)
        return answer;

      llint minvalue = store.top();
      store.pop();
      llint maxvalue = store.top();
      store.pop();

      answer++;
      llint newvalue = (minvalue * 2) + maxvalue;
      store.push(newvalue);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
