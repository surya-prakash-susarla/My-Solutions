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
  int minOperations(vector<string>& logs) {
    int counter = 0;

    for (const string& i : logs) {
      const string folder = i.substr(0, i.find('/'));
      if (folder == ".")
        continue;
      else if (folder == "..")
        counter <= 0 ? counter = counter : counter--;
      else
        counter++;
    }

    return counter;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
