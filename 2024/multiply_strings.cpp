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
  string single_digit_multiply(const string& a, char b) {
    int carry = 0;
    string answer;
    const int dig2 = b - '0';
    for (int i = 0; i < a.size(); i++) {
      int dig1 = a[i] - '0';
      int current = dig1 * dig2;
      current += carry;
      int final_dig = current % 10;
      carry = current / 10;
      answer += ('0' + final_dig);
    }
    if (carry > 0)
      answer += ('0' + carry);
    return answer;
  }

  inline string pad_with_zero(string a, int count) {
    return string(count, '0') + a;
  }

  string add(vector<string> values) {
    string answer;
    int carry = 0;
    int ind = 0;
    while (true) {
      int current = 0;
      bool found = false;
      for (int i = 0; i < values.size(); i++) {
        if (ind < values[i].size()) {
          current += (values[i][ind] - '0');
          found = true;
        }
      }
      if (not found)
        break;
      current += carry;
      int dig = current % 10;
      carry = current / 10;
      ind++;
      answer += ('0' + dig);
    }
    if (carry > 0)
      answer += ('0' + carry);
    return answer;
  }

  string mul(const string& oa, const string& ob) {
    if (oa == "0" or ob == "0")
      return "0";
    if (oa == "1")
      return ob;
    if (ob == "1")
      return oa;

    string a = oa;
    string b = ob;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<string> results;
    for (int i = 0; i < b.size(); i++) {
      string current = single_digit_multiply(a, b[i]);
      current = pad_with_zero(current, i);
      results.emplace_back(current);
    }

    string answer = add(results);
    reverse(answer.begin(), answer.end());
    return answer;
  }

  string multiply(string num1, string num2) { return mul(num1, num2); }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
