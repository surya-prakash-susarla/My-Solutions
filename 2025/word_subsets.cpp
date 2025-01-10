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
  vector<string> wordSubsets(vector<string>& target, vector<string>& source) {
#define char_ind(x) x - 'a'
    typedef vector<int> vint;

    vint source_counts(26, 0);
    for (const string& i : source) {
      vint temp(26, 0);
      for (char c : i)
        temp[char_ind(c)]++;

      for (int j = 0; j < 26; j++)
        source_counts[j] = max(source_counts[j], temp[j]);
    }

    vector<string> answer;
    for (const string& i : target) {
      vint temp(26, 0);
      for (char c : i)
        temp[char_ind(c)]++;

      bool is_valid = true;
      for (int j = 0; j < 26; j++)
        if (temp[j] < source_counts[j]) {
          is_valid = false;
          break;
        }

      if (is_valid)
        answer.emplace_back(i);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
