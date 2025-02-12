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
  bool validWordAbbreviation(string target, string input) {
    int i, j;
    for (i = 0, j = 0; j < input.size() and i < target.size();) {
      if (input[j] >= '0' and input[j] <= '9') {
        int start = j;

        for (j++; j < input.size() and input[j] >= '0' and input[j] <= '9'; j++)
          ;

        string num_value = input.substr(start, j - start);
        if (num_value[0] == '0')
          return false;
        int value = stoi(num_value);
        i += value;
      } else {
        if (target[i] != input[j])
          return false;

        i++;
        j++;
      }
    }

    return (i == target.size() and j == input.size());
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
