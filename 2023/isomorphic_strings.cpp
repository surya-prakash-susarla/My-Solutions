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
  inline void trans(string& a) {
    char c = 'a';
    map<char, char> temp;
    for (int i = 0; i < a.size(); i++) {
      auto it = temp.find(a[i]);
      if (it != temp.end()) {
        a[i] = it->second;
      } else {
        temp[a[i]] = c;
        a[i] = c++;
      }
    }
  }

  bool isIsomorphic(string a, string b) {
    if (a.size() != b.size())
      return false;
    trans(a);
    trans(b);
    return a == b;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
