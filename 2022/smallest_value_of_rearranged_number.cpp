#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  long long smallestNumber(long long num) {
    bool is_neg = num < 0;
    if (is_neg)
      num = 0 - num;
    string dig = to_string(num);
    sort(dig.begin(), dig.end());

    // for(char c : dig )  cout << c << " " ;
    // cout << endl;

    if (is_neg) {
      reverse(dig.begin(), dig.end());
      long long answer = stoll(dig);
      answer = 0 - answer;
      return answer;
    } else {
      int nzi = 0;
      for (int i = 0; i < dig.size(); i++) {
        if (dig[i] != '0') {
          nzi = i;
          break;
        }
      }
      string answer(dig.size(), ' ');
      answer[0] = dig[nzi];
      int x = 1;
      for (int i = 0; i < nzi; i++)
        answer[x++] = '0';
      for (int i = nzi + 1; i < dig.size(); i++)
        answer[x++] = dig[i];
      long long answer_value = stoll(answer);
      return answer_value;
    }
  }
};