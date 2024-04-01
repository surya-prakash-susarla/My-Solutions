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
  int lengthOfLastWord(string input) {
    int start_index = input.size() - 1;

    for (; start_index > -1 and input[start_index] == ' '; start_index--)
      ;

    int answer = 0;
    for (; start_index > -1 and input[start_index] != ' '; start_index--)
      answer++;

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
