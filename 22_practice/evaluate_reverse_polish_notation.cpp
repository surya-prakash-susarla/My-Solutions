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
  typedef long long int llint;

  string div = "/";
  string mul = "*";
  string add = "+";
  string sub = "-";

  llint magic = numeric_limits<llint>::min();

  llint response(llint a, llint b, const string& op) {
    if (op == div)
      return a / b;
    if (op == mul)
      return a * b;
    if (op == add)
      return a + b;
    if (op == sub)
      return a - b;
    return magic;
  }

  inline bool is_sym(const string& a) { return response(1, 1, a) != magic; }

  void print_stack(stack<string> values) {
    cout << "dumping stack" << endl;
    while (not values.empty()) {
      cout << values.top() << " ";
      values.pop();
    }
    cout << endl;
    return;
  }

  int evalRPN(vector<string>& tokens) {
    stack<string> values;
    for (const string& i : tokens) {
      if (is_sym(i)) {
        //   cout << "currently processing symbol : " << i << endl;
        llint op1 = stol(values.top());
        values.pop();
        llint op2 = stol(values.top());
        values.pop();
        values.push(to_string(response(op2, op1, i)));
      } else {
        //   cout << "pushing symbol : " << i << endl;
        values.push(i);
      }
      //   cout << "current token : " << i << endl;
      //   print_stack(values);
      //   cout << string(5, '*') << endl;
    }
    return stoi(values.top());
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
