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
  string input;

  vector<vector<int>> memo;

  bool is_palindrome(int i, int j) {
    // cout << "checking substring : " << input.substr(i, j-i+1) << endl;
    if (i >= j)
      return true;
    if (memo[i][j] != -1) {
      return memo[i][j];
    }
    const bool answer = (input[i] == input[j]) and is_palindrome(i + 1, j - 1);
    memo[i][j] = answer;
    return answer;
  }

  string longestPalindrome(string input) {
    this->input = input;

    memo = vector<vector<int>>(input.size(), vector<int>(input.size(), -1));

    int start = 0;
    int end = 0;
    for (int i = 0; i < input.size(); i++) {
      for (int j = i; j < input.size(); j++) {
        if (is_palindrome(i, j) and (j - i + 1) > (end - start + 1)) {
          start = i;
          end = j;
        }
      }
    }

    return input.substr(start, end - start + 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
