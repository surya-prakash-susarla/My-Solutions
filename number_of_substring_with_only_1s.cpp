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
  int modulo = 1000000007;

  int counter(int len) {
    long long a = len;
    long long b = (len + 1);

    a %= modulo;
    b %= modulo;

    long long temp = a * b;
    temp %= modulo;

    return temp / 2;
  }

  int numSub(string s) {
    int current = 0;

    int answer = 0;

    for (char c : s) {
      if (c == '1') {
        current++;
      } else {
        answer += counter(current);
        current = 0;
      }
    }

    answer += counter(current);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}