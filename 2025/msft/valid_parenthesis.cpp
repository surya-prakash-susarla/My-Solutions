class Solution {
 public:
  bool isValid(string input) {
    stack<char> values;
    for (char c : input) {
      switch (c) {
        case '(':
        case '[':
        case '{': {
          values.push(c);
          break;
        }
        case ')': {
          if (values.empty())
            return false;
          if (values.top() != '(')
            return false;
          values.pop();
          break;
        }
        case ']': {
          if (values.empty())
            return false;
          if (values.top() != '[')
            return false;
          values.pop();
          break;
        }
        case '}': {
          if (values.empty())
            return false;
          if (values.top() != '{')
            return false;
          values.pop();
          break;
        }
      }
    }
    return values.empty();
  }
};
