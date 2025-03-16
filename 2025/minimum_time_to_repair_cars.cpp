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
  typedef long long ll;

  vector<int> input;
  ll n;

  bool is_valid(ll time) {
    auto get_val = [](int r, ll t) -> ll { return floor(sqrt(t / r)); };

    int req = n;
    for (int i : input) {
      req -= get_val(i, time);
      if (req <= 0)
        return true;
    }
    return false;
  }

  long long repairCars(vector<int>& ranks, int cars) {
    input = ranks;
    n = cars;

    ll left = 1;
    ll right = (*max_element(ranks.begin(), ranks.end()) * n * n);

    ll answer = right;

    while (left <= right) {
      const ll current = (left + right) / 2;
      if (is_valid(current)) {
        answer = min(answer, current);
        right = current - 1;
      } else {
        left = current + 1;
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
