#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
int prec(char c) {
  switch (c) {
  case '+':
    return 1;
  case '-':
    return 2;
  case '*':
    return 3;
  case '/':
    return 4;
  case '^':
    return 5;
  }
  return 0;
}
void disp(stack<char> f) {
  stack<char> r;
  while (!f.empty()) {
    r.push(f.top());
    f.pop();
  }
  while (!r.empty()) {
    if (r.top() != '@')
      cout << r.top();
    r.pop();
  }
}
int main() {
  int t;
  cin >> t;
  for (int u = 0; u < t; u++) {
    string s;
    cin >> s;
    stack<char> answer, oper;
    // cout<<s.length()<<endl;
    oper.push('@');
    for (int i = 0; i < s.length(); i++) {
      if (isalpha(s[i])) {
        answer.push(s[i]);
        // disp(answer);
      } else if (s[i] == '(')
        oper.push(s[i]);
      else if (s[i] == ')') {
        char c = oper.top();
        oper.pop();
        while (c != '(') {
          answer.push(c);
          c = oper.top();
          oper.pop();
        }
      } else {
        if (oper.top() == '@')
          oper.push(s[i]);
        else {
          if (prec(oper.top()) >= prec(s[i])) {
            char c = oper.top();
            oper.pop();
            answer.push(c);
            oper.push(s[i]);
          } else {
            oper.push(s[i]);
          }
        }
      }
    }
    while (!oper.empty()) {
      answer.push(oper.top());
      oper.pop();
    }
    disp(answer);
    if (u < t - 1)
      cout << endl;
  }
  return 0;
}
