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
  string removeDuplicates(string s) {
    int left = 0;
    int right = 1;

    while (right < s.size()) {
      // cout << left << " , " << right << endl;
      if (s[left] == s[right]) {
        // cout << "marking indices" << endl;
        s[left] = '@';
        s[right] = '@';
        right++;
        while (left > -1 and s[left] == '@')
          left--;
        if (left == -1) {
          left = right++;
        }
      } else {
        left = right++;
      }
    }

    string answer;
    for (char c : s)
      if (c != '@')
        answer += c;
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
