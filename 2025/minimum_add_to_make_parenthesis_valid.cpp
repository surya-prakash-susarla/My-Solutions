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
  int minAddToMakeValid(string s) {
    int answer = 0;
    int count = 0;
    for (char c : s) {
      if (c == '(') {
        count++;
      } else {
        if (count == 0) {
          answer++;
        } else {
          count--;
        }
      }
    }
    answer += count;
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
