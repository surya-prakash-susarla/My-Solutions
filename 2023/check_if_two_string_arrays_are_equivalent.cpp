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
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string first;
    for (string i : word1)
      first += i;
    string second;
    for (string i : word2)
      second += i;

    return first == second;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
