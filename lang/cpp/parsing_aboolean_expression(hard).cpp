class Solution {
 public:
  stack<int> values, ops;
  int sym_convert(char c) {
    switch (c) {
      case ',':
      case '(':
        return -1;
      case ')':
        return -2;
      case 'f':
        return 0;
      case 't':
        return 1;
      case '!':
        return 2;
      case '&':
        return 3;
      case '|':
        return 4;
      default:
        return -1;
    }
  }

  int calc_op(int op, int a, int b) {
    if (op == 3)
      return (bool)a && (bool)b;
    else
      return (bool)a || (bool)b;
  }

  bool parseBoolExpr(string expression) {
    for (char c : expression) {
      int ret_value = sym_convert(c);
      switch (ret_value) {
        case -1:
          break;
        case -2: {
          int result = this->values.top();
          this->values.pop();
          if (this->ops.top() == 2)
            result = not(bool) result;
          else
            while (this->values.top() != -1) {
              result = calc_op(this->ops.top(), this->values.top(), result);
              this->values.pop();
            }
          this->values.pop();
          this->values.push(result);
          this->ops.pop();
          break;
        }
        case 0 ... 1:
          this->values.push(ret_value);
          break;
        case 2 ... 4:
          this->values.push(-1);
          this->ops.push(ret_value);
          break;
      }
    }
    return (bool)this->values.top();
  }
};