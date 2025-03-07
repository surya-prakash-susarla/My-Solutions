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
  bool check(int start, int end, const string& input) {
    while (start <= end) {
      if (input[start++] != input[end--])
        return false;
    }
    return true;
  }

  int countSubstrings(string input) {
    int answer = input.size();

    for (int i = 1; i < input.size(); i++)
      for (int j = 0; j + i < input.size(); j++)
        if (check(j, j + i, input))
          answer++;

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
