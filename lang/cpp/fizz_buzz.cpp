#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    string a = "Fizz", b = "Buzz";
    vector<string> answer;
    for (int i = 1; i <= n; i++) {
      if (i % 3 == 0 and i % 5 == 0)
        answer.push_back(a + b);
      else if (i % 3 == 0)
        answer.push_back(a);
      else if (i % 5 == 0)
        answer.push_back(b);
      else
        answer.push_back(to_string(i));
    }
    return answer;
  }
};