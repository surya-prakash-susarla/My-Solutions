#include <bits/stdc++.h>

using namespace std;

/* Test Cases
"isfcow#"
"isfco#w#"
"ab#c"
"ad#c"
"ab##"
"c#d#"
"a#c"
"b"
"xywrrmp"
"xywrrmu#p"
*/

class Solution {
 public:
  void modify(string& input) {
    int h = 0;
    for (int i = input.size() - 1; i > -1; i--) {
      if (input[i] == '#') {
        h++;
      } else {
        if (h > 0) {
          input[i] = '#';
          h--;
        }
      }
    }
  }

  bool backspaceCompare(string a, string b) {
    modify(a);
    modify(b);

    int i = -1;
    int j = -1;

    while (i < (int)a.size() and j < (int)b.size()) {
      for (i = i + 1; i < a.size() and a[i] == '#'; i++)
        ;
      for (j = j + 1; j < b.size() and b[j] == '#'; j++)
        ;
      if (i < a.size() and j < b.size())
        if (a[i] != b[j])
          return false;
    }

    return i >= a.size() and j >= b.size();
  }
};
