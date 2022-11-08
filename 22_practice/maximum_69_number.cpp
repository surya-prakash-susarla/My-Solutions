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
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Solution {
 public:
  int maximum69Number(int num) {
    string temp = to_string(num);
    for (int i = 0; i < temp.size(); i++)
      if (temp[i] == '6') {
        temp[i] = '9';
        break;
      }
    return stoi(temp);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
