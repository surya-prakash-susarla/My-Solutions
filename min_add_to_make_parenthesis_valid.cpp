class Solution {
 public:
  int minAddToMakeValid(string input) {
    stack<char> values;
    for (char c : input)
      if (not values.empty())
        if (values.top() == '(' and c == ')')
          values.pop();
        else
          values.push(c);
      else
        values.push(c);
    return values.size();
  }
};