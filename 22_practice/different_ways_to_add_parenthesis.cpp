#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  typedef vector<int> vint;
  typedef vector<vint> vvint;

  struct token final {
    optional<int> value;
    optional<char> op;
    token() = delete;
    token(int a) : value(a){};
    token(char a) : op(a){};
  };

  vector<token> _break(const string& input) {
    vector<token> answer;
    string temp;
    for (int i = 0; i < input.size(); i++) {
      if (isdigit(input[i])) {
        temp += input[i];
      } else {
        answer.emplace_back(token(stoi(temp)));
        answer.emplace_back(token(input[i]));
        temp = string();
      }
    }
    answer.push_back(token(stoi(temp)));
    return answer;
  }

  inline int _op(int a, int b, char c) {
    switch (c) {
      case '+':
        return a + b;
      case '-':
        return a - b;
      case '*':
        return a * b;
      default: {
        return numeric_limits<int>::max();
      }
    }
  }

  inline void _generate(vint& answer,
                        const vint& left,
                        const vint& right,
                        char op) {
    for (int i : left)
      for (int j : right)
        answer.push_back(_op(i, j, op));
    return;
  }

  vint _calc(int start, int end) {
    if (start > end or end < start)
      return {};
    if (not memo[start][end].empty())
      return memo[start][end];
    if (start == end) {
      memo[start][end] = {values[start].value.value()};
      return memo[start][end];
    }
    vector<int> answer;
    for (int i = start; i <= end; i++)
      if (values[i].op.has_value())
        _generate(answer, _calc(start, i - 1), _calc(i + 1, end),
                  values[i].op.value());
    memo[start][end] = answer;
    return answer;
  }

  vector<int> diffWaysToCompute(string expression) {
    values = _break(expression);
    memo = vector<vvint>(values.size(), vvint(values.size()));
    return _calc(0, values.size() - 1);
  }

  vector<token> values;
  vector<vvint> memo;
};
