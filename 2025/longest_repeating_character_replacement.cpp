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
  int characterReplacement(string input, int k) {
    vector<int> counts(26, 0);

    int left = 0;
    int answer = 0;

    for (int i = 0; i < input.size(); i++) {
      counts[input[i] - 'A']++;
      int me = *max_element(counts.begin(), counts.end());

      while ((i - left + 1) - me > k) {
        counts[input[left++] - 'A']--;
      }

      answer = max(answer, (i - left + 1));
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
