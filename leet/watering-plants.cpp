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
  int wateringPlants(vector<int>& plants, int capacity) {
    int current = capacity;

    typedef long long int llint;
    llint cost = 0;

    int cd = 0;

    for (int i = 0; i < plants.size(); i++) {
      cd++;
      if (plants[i] <= current) {
        current -= plants[i];
        cost += 1;
      } else {
        cost += (2 * (cd - 1) + 1);
        current = capacity - plants[i];
      }
    }

    return cost;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
