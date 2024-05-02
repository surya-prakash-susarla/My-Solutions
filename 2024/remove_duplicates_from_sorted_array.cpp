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
  int removeDuplicates(vector<int>& values) {
    int answer = 1;
    for (int i = 1; i < values.size(); i++) {
      if (values[i] <= values[i - 1]) {
        int b = -1;
        for (int j = i + 1; j < values.size(); j++)
          if (values[j] > values[i - 1]) {
            b = j;
            break;
          }
        if (b == -1)
          return answer;
        answer++;
        swap(values[i], values[b]);
      } else {
        answer++;
      }
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
