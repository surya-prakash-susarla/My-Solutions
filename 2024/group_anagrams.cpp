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
  vector<vector<string>> groupAnagrams(vector<string>& values) {
    map<map<char, int>, vector<string>> temp;
    for (string i : values) {
      map<char, int> temp2;
      for (char c : i)
        temp2[c]++;
      temp[temp2].emplace_back(i);
    }
    vector<vector<string>> answer;
    for (auto i : temp)
      answer.emplace_back(i.second);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
