class Solution {
 public:
  int myAtoi(string s) {
    int start = 0;

    // trim
    for (; start < s.size(); start++)
      if (s[start] != ' ')
        break;

    if (start == s.size())
      return 0;

    bool is_neg = false;
    if (s[start] == '-') {
      is_neg = true;
      start++;
    } else if (s[start] == '+') {
      start++;
    }

    // skip zeros
    for (; start < s.size(); start++)
      if (s[start] != '0')
        break;

    int end = s.size();
    for (end = start; end < s.size(); end++)
      if (s[end] < '0' or s[end] > '9')
        break;

    string final_num = s.substr(start, end - start);
    if (final_num.empty())
      return 0;

    typedef unsigned long long ull;

    auto calc_value = [](const string& input) -> optional<int> {
      if (input.size() == 0)
        return 0;

      int answer = 0;
      int p = 0;
      for (int i = input.size() - 1; i >= 0; i--) {
        if (p >= 11)
          return nullopt;
        long long current = answer + ((input[i] - '0') * (pow(10, p)));

        if (current > INT_MAX)
          return nullopt;

        p++;
        answer = current;
      }

      return answer;
    };

    optional<int> value = calc_value(final_num);
    if (not value.has_value())
      return is_neg ? INT_MIN : INT_MAX;

    if (is_neg) {
      if (*value > (0 - (ull)INT_MIN))
        return INT_MIN;
      return -(*value);
    } else {
      if (*value > INT_MAX)
        return INT_MAX;
      return *value;
    }
  }
};
