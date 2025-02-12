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
  string simplifyPath(string input) {
    stack<string> path;
    for (int i = 1; i < input.size();) {
      // find the first '/'
      int j;
      for (j = i; j < input.size(); j++) {
        if (input[j] == '/')
          break;
      }

      string folder = input.substr(i, j - i);
      // cout << "Folder : " << folder << endl;

      if (folder.empty() or folder == ".") {
        // skip cause it doesn't mean anything
      } else if (folder == "..") {
        if (not path.empty())
          path.pop();
      } else {
        path.push(folder);
      }

      while (j < input.size()) {
        if (input[j] != '/')
          break;
        j++;
      }

      i = j;
    }

    string answer = "";
    while (not path.empty()) {
      answer = path.top() + (answer.size() ? string("/") : string()) + answer;
      path.pop();
    }

    answer = "/" + answer;
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
