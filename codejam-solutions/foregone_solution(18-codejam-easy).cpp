#include <iostream>
#include <string>
using namespace std;
typedef unsigned int uint;

int main() {
  uint test_cases;
  scanf("%d", &test_cases);
  for (uint i = 1; i <= test_cases; i++) {
    string input;
    cin >> input;
    string input_2;
    bool init = false;
    for (size_t j = 0; j < input.size(); j++)
      if (init || input[j] == '4') {
        if (input[j] == '4') {
          input[j] = '2';
          input_2.insert(input_2.end(), '2');
        } else
          input_2.insert(input_2.end(), '0');
        init = true;
      }
    cout << "Case #" << i << ": " << input << " " << input_2;
    if (i < test_cases)
      cout << endl;
  }
}