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
  long long __calc__(int size) {
    long long answer = 0;
    for (int i = 1; i <= size; i++) {
      answer += (size - i + 1);
    }
    return answer;
  }
  long long zeroFilledSubarray(vector<int>& values) {
    int index = 0;
    long long answer = 0;
    while (index < values.size()) {
      if (values[index] == 0) {
        long long size = 0;
        while (index < values.size() and values[index] == 0) {
          size += 1;
          index += 1;
        }
        answer += __calc__(size);
      } else {
        index += 1;
      }
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
