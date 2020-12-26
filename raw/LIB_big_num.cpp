#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class big_int {
 public:
  string value;

  big_int() { value = ""; };

  big_int(string value) { this->value = value; };

  void get(string value) {
    this->value = value;
    return;
  };

  big_int operator+(const big_int& right_value) {
    string lvalue = this->value, rvalue = right_value.value;
    vector<char> result;
    reverse(lvalue.begin(), lvalue.end());
    reverse(rvalue.begin(), rvalue.end());
    int diff = lvalue.size() - rvalue.size();
    if (diff > 0) {
      string zeroes(diff, '0');
      rvalue = rvalue + zeroes;
    } else if (diff < 0) {
      string zeroes(0 - diff, '0');
      lvalue = lvalue + zeroes;
    }
    int i = 0, j = 0, increment = 0;
    while (i < lvalue.size() and j < rvalue.size()) {
      int answer = (lvalue[i++] - '0') + (rvalue[j++] - '0') + increment;
      result.push_back(char(answer % 10 + '0'));
      increment = answer / 10;
    }
    if (increment > 0)
      result.push_back(char(increment + '0'));
    reverse(result.begin(), result.end());
    string final_result(result.begin(), result.end());
    big_int temp(final_result);
    return temp;
  };

  big_int operator-(const big_int& right_value) {
    string lvalue = this->value, rvalue = right_value.value;
    vector<char> result;
    reverse(lvalue.begin(), lvalue.end());
    reverse(rvalue.begin(), rvalue.end());
    int diff = lvalue.size() - rvalue.size();
    bool pos_result = true;
    if (diff > 0) {
      string zeroes(diff, '0');
      rvalue = rvalue + zeroes;
    } else if (diff < 0) {
      pos_result = false;
      string zeroes(0 - diff, '0');
      lvalue = lvalue + zeroes;
    }

    cout << "lvalue = " << lvalue << endl;
    cout << "rvalue = " << rvalue << endl;

    int i = 0, j = 0;
    bool borrow = false;
    while (i < lvalue.size() and j < rvalue.size()) {
      int top_digit = lvalue[i] - '0', low_digit = rvalue[i] - '0';
      if (borrow) {
        top_digit -= 1;
        borrow = false;
      }
      if (top_digit < low_digit) {
        top_digit += 10;
        borrow = true;
      }
      int answer = top_digit - low_digit;
      result.push_back(char(answer + '0'));
      i++, j++;
    }
    if (borrow)
      result.push_back('-');
    reverse(result.begin(), result.end());
    string final_result(result.begin(), result.end());
    big_int temp(final_result);
    return temp;
  };

  big_int single_char_mul(string input, char mul_dig) {
    if (mul_dig == '0')
      return string(input.size(), '0');
    vector<char> final_answer;
    reverse(input.begin(), input.end());
    int i = 0, digit = mul_dig - '0', increment = 0;
    while (i < input.size()) {
      int answer = ((input[i] - '0') * digit) + increment;
      if (answer >= 10) {
        increment = answer / 10;
        answer = answer % 10;
      } else
        increment = 0;
      final_answer.push_back(char(answer + '0'));
      i++;
    }
    if (increment > 0)
      final_answer.push_back(char(increment + '0'));
    reverse(final_answer.begin(), final_answer.end());
    string final_result(final_answer.begin(), final_answer.end());
    big_int temp(final_result);
    return temp;
  }

  big_int operator*(const big_int& right_value) {
    string lvalue = this->value, rvalue = right_value.value;
    reverse(rvalue.begin(), rvalue.end());
    vector<big_int> values;
    int i = 0;
    while (i < rvalue.size()) {
      char digit = rvalue[i];
      big_int current_value = single_char_mul(lvalue, digit);
      string zeroes(i, '0');
      string solution = current_value.value + zeroes;
      big_int temp(solution);
      values.push_back(temp);
      i++;
    }
    big_int init = values[0];
    for (int i = 1; i < values.size(); i++) {
      init = init + values[i];
    }
    return init;
  };

  big_int min(big_int value) {
    if (this->value.size() < value.value.size())
      return *this;
    else if (this->value.size() > value.value.size())
      return value;
    else {
      int i = 0;
      while (i < this->value.size()) {
        if (this->value[i] - '0' < value.value[i] - '0')
          return *this;
        else if (this->value[i] - '0' > value.value[i] - '0')
          return value;
        i++;
      }
      // both numbers are equal
      return value;
    }
    return value;
  };
};

/*
int main() {
    big_int a,b;
    string input;
    cin >> input ;
    a.get(input);
    cout << "Value of a = " << a.value << endl;
    cin >> input;
    b.get(input);
    cout << "Value of b = " << b.value << endl;

    cout << "starting mul "<<endl;
    big_int temp_sub  = a*b;
    cout << temp_sub.value << endl;
    return 0;
}
*/