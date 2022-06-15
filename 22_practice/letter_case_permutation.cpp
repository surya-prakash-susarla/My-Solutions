#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<string> letterCasePermutation(string s) {
    vector<string> answer = {""};

    for (char c : s) {
      vector<string> temp;
      if (isalpha(c)) {
        char low = tolower(c);
        for (string i : answer)
          temp.emplace_back(i + low);
        char up = toupper(c);
        for (string i : answer)
          temp.emplace_back(i + up);
      } else {
        for (string i : answer)
          temp.emplace_back(i + c);
      }
      swap(answer, temp);
    }

    return answer;
  }
};