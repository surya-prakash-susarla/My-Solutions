#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    float temp_answer = (float)numerator / denominator;
    string answer = to_string(temp_answer);
    string decimal_part = answer.substr(answer.find('.') + 1, string::npos);
    string final_decimal_part = "";
    cout << "the answer in float format is " << temp_answer << endl;
    for (int i = 0; i < decimal_part.size(); i++) {
      if (not is_significant(decimal_part.substr(i + 1, string::npos))) {
        final_decimal_part += decimal_part[i];
        break;
      }
      if (is_repeated(decimal_part[i],
                      decimal_part.substr(i + 1, string::npos))) {
        cout << "character is repeated " << decimal_part[i] << endl;
        cout << " the existing final decimal part is " << final_decimal_part
             << endl;
        final_decimal_part = final_decimal_part + '(' + decimal_part[i] + ')';
        cout << "the updated decimal part is " << final_decimal_part << endl;
        break;
      }
      final_decimal_part += decimal_part[i];
    }
    return answer.substr(0, answer.find('.')) + "." + final_decimal_part;
  }

  bool is_significant(string value) {
    for (int i = 0; i < value.size(); i++)
      if (value[i] != '0')
        return true;
    return false;
  }

  bool is_repeated(char number, string input) {
    bool rounded = false;
    for (int i = 0; i < input.size(); i++) {
      if (input[i] == number + 1 and not rounded)
        rounded = true;
      else if (input[i] != number and input[i] != number + 1)
        return false;
      else if (input[i] == number + 1 and rounded)
        return false;
    }
    return true;
  }
};

int main() {
  Solution temp_obj;

  int a, b;
  cin >> a >> b;

  cout << temp_obj.fractionToDecimal(a, b) << endl;
  return 0;
}