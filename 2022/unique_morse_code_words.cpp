#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> kConversions = {
        ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
        ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
        "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};

    set<string> values;
    for (const string i : words) {
      string temp;
      for (char c : i) {
        temp = temp + kConversions[c - 'a'];
      }
      values.insert(temp);
    }

    return values.size();
  }
};
