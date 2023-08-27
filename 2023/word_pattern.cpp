#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Solution {
 public:
  bool wordPattern(string input, string val) {
    vector<string> values;
    {
      string temp;
      for (int i = 0; i < val.size(); i++) {
        if (val[i] == ' ') {
          values.emplace_back(temp);
          temp = "";
        } else {
          temp += val[i];
        }
      }
      values.emplace_back(temp);
    }

    if (input.size() != values.size())
      return false;

    string temp2;
    {
      char c = 'a';
      map<string, char> temp;
      for (const string& i : values) {
        auto it = temp.find(i);
        if (it != temp.end()) {
          temp2 += it->second;
        } else {
          temp[i] = c;
          temp2 += c;
          c++;
        }
      }
    }

    string temp3;
    {
      char c = 'a';
      map<char, char> temp;
      for (char i : input) {
        auto it = temp.find(i);
        if (it != temp.end()) {
          temp3 += it->second;
        } else {
          temp[i] = c;
          temp3 += c;
          c++;
        }
      }
    }

    return temp3 == temp2;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
