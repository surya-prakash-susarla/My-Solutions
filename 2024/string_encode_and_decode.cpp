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
  string encode(vector<string>& strs) {
    string answer;

    for (const string& i : strs) {
      string len = to_string(i.size());
      if (len.size() < 3) {
        len = string(3 - len.size(), '0') + len;
      }

      string encoded_string = len + i;
      answer += encoded_string;
    }

    return answer;
  }

  vector<string> decode(string s) {
    vector<string> answer;

    int index = 0;

    while (index < s.size()) {
      string temp_len = s.substr(index, 3);
      int len = stoi(temp_len);
      index += 3;
      answer.push_back(s.substr(index, len));
      index += len;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
