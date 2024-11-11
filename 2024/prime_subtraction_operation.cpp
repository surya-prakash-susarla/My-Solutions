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
  set<int> getPrime(int limit) {
    vector<bool> values(limit + 1, true);
    for (int i = 2; i <= limit; i++) {
      if (not values[i]) {
        continue;
      } else {
        for (int j = 2; i * j <= limit; j++)
          values[i * j] = false;
      }
    }
    set<int> answer;
    for (int i = 2; i <= limit; i++)
      if (values[i])
        answer.insert(i);

    return answer;
  }

  optional<set<int>::iterator> getLargestPrime(int value,
                                               const set<int>& primes) {
    auto it = primes.lower_bound(value);

    if (it == primes.end()) {
      return prev(primes.end());
    }

    if (it == primes.begin()) {
      if (*it == value)
        return nullopt;
      else
        return it;
    }
    while (*it >= value) {
      if (it == primes.begin())
        return nullopt;
      it = prev(it);
    }

    return it;
  }

  bool primeSubOperation(vector<int>& input) {
    if (input.size() == 1)
      return true;

    int maxvalue = -1;
    for (int i : input)
      maxvalue = max(maxvalue, i);

    set<int> primes = getPrime(maxvalue);

    int last_value = -1;

    for (int i : input) {
      int original_value = i;

      int mut_value = INT_MAX;
      optional<set<int>::iterator> it = getLargestPrime(i, primes);
      if (it.has_value()) {
        bool valid = true;
        while (valid) {
          int sub_value = i - (*it.value());
          if (sub_value <= last_value) {
            if (it == primes.begin()) {
              valid = false;
              break;
            } else {
              it = prev(it.value());
            }
          } else {
            mut_value = sub_value;
            valid = false;
          }
        }
      }
      const int final_value = min(original_value, mut_value);

      if (final_value <= last_value)
        return false;

      last_value = final_value;
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
