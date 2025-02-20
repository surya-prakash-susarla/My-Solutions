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
  string add(string a, string b) {
    string answer;

    int ai = 0;
    int bi = 0;

    int carry = 0;

    for (; ai < a.size() and bi < b.size(); ai++, bi++) {
      int sumval = (a[ai] - '0') + (b[bi] - '0');
      sumval += carry;

      carry = (sumval / 10);
      int dig = (sumval % 10);

      answer += (dig + '0');
    }

    for (; ai < a.size(); ai++) {
      int sumval = (a[ai] - '0') + carry;
      carry = (sumval / 10);
      int dig = (sumval % 10);
      answer += (dig + '0');
    }

    for (; bi < b.size(); bi++) {
      int sumval = (b[bi] - '0') + carry;
      carry = (sumval / 10);
      int dig = (sumval % 10);
      answer += (dig + '0');
    }

    if (carry != 0) {
      answer += (carry + '0');
    }

    // cout << "a : " << a << " , b : " << b << " , result : " << answer <<
    // endl;

    return answer;
  }

  string mul(string a, char b) {
    string answer;

    int carry = 0;
    const int b_dig = b - '0';
    for (char c : a) {
      int mulval = (c - '0') * b_dig;
      mulval += carry;

      carry = (mulval / 10);
      int current_digit = (mulval % 10);

      answer += ('0' + current_digit);
    }

    if (carry != 0)
      answer += ('0' + carry);

    // cout << "for source : " << a << " , target : " << b << " , result : " <<
    // answer;
    return answer;
  }

  string multiply(string a, string b) {
    if (a == "0" or b == "0")
      return "0";

    string answer;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < b.size(); i++) {
      string result = mul(a, b[i]);
      result = string(i, '0') + result;
      answer = add(answer, result);
    }

    reverse(answer.begin(), answer.end());
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
