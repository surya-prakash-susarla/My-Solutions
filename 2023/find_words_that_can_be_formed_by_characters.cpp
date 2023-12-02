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
  typedef vector<int> vint;

  int countCharacters(vector<string>& words, string chars) {
    vint avail(26);
    for (char c : chars)
      avail[c - 'a']++;

    int answer = 0;
    for (string i : words) {
      vint current(26);
      for (char c : i)
        current[c - 'a']++;
      bool failed = false;
      for (int i = 0; i < 26; i++)
        if (current[i] > avail[i]) {
          failed = true;
          break;
        }
      if (failed)
        continue;
      else
        answer += i.size();
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
