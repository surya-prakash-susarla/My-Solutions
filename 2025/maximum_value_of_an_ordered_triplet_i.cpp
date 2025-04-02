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
  long long maximumTripletValue(vector<int>& input) {
    typedef long long ll;

    vector<int> greatest(input);

    for (int i = input.size() - 2; i > -1; i--) {
      greatest[i] = max(greatest[i + 1], input[i + 1]);
    }

    ll answer = 0;
    for (int i = 0; i < input.size() - 2; i++) {
      for (int j = i + 1; j < input.size() - 1; j++) {
        if (input[j] >= input[i])
          continue;

        ll temp = (input[i] - input[j]) * (ll)greatest[j];
        answer = max(answer, temp);
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
