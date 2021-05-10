#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> values;

    for (const std::string& i : strs) {
      std::string temp = i;
      sort(temp.begin(), temp.end());
      values[temp].push_back(i);
    }

    std::vector<std::vector<std::string>> answer;
    for (const std::pair<std::string, std::vector<std::string>>& i : values) {
      answer.push_back(i.second);
    }

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
