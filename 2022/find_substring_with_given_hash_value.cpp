#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int getval(char c) { return c - 'a' + 1; }

  string subStrHash(string s, int power, int modulo, int k, int hashValue) {
    typedef unsigned long long int llint;

    llint ih = 0;
    llint pw = 1;
    llint pwk = 0;

    for (int i = s.size() - k; i < s.size(); i++) {
      llint lhs = getval(s[i]) % modulo;
      llint rhs = pw;
      llint tr = (lhs * rhs) % modulo;
      ih = ih + tr;
      ih = ih % modulo;

      if (i + 1 != s.size()) {
        pw = (pw * power) % modulo;
      } else {
        pwk = pw;
      }
    }

    // cout << "initial index from : " << s.size() - k << endl ;
    // cout << " value : " << ih << endl;
    // cout << " pwk value : " << pwk << endl << endl ;

    int answer = ih == hashValue ? s.size() - k : s.size();

    for (int i = s.size() - k - 1; i > -1; i--) {
      // cout << "at index : " << i << endl;
      llint removal_value = ((getval(s[i + k]) % modulo) * (pwk)) % modulo;
      // cout << "removal value : " << removal_value << endl;

      if (ih < removal_value) {
        // cout << "ih : " << ih << " , removal value : " << removal_value <<
        // endl;
        ih = (modulo - (removal_value - ih));
        // cout << "new ih : " << ih << endl;
      } else {
        ih = ih - removal_value;
      }

      // cout << "value after removal : " << ih << endl;

      ih = ih * power;
      ih = ih % modulo;

      // cout << "after updating power : " << ih << endl;

      ih = ih + (getval(s[i]) % modulo);
      ih = ih % modulo;

      // cout << "value after add : " << ih << endl;

      // cout << "Hash at index : " << i << " , is : " << ih << endl << endl;

      if (ih == hashValue)
        answer = i;
    }

    // cout << "Final answer at index : " << answer ;
    if (answer == s.size()) {
      // cout << "cannot find hash" << endl;
      return "";
    }
    return s.substr(answer, k);
  }
};