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
  inline bool check_maps(map<char, int>& source, const map<char, int>& target) {
    for (const pair<char, int>& i : target)
      if (source[i.first] < i.second)
        return false;
    return true;
  }

  string search(const string& values,
                int length,
                const map<char, int>& counts) {
    map<char, int> temp;
    for (int i = 0; i < length; i++)
      temp[values[i]]++;
    if (check_maps(temp, counts))
      return values.substr(0, length);
    for (int i = length; i < values.size(); i++) {
      temp[values[i - length]]--;
      temp[values[i]]++;
      if (check_maps(temp, counts))
        return values.substr(i - length + 1, length);
    }
    return "";
  }

  string minWindow(string values, string target) {
    int worst = target.size() - 1;
    int best = values.size();

    map<char, int> main_count;
    for (char c : target)
      main_count[c]++;

    bool is_valid = true;
    int current = best;
    string answer = "";
    while (worst < best) {
      if (worst == current)
        break;
      string temp = search(values, current, main_count);
      if (temp.empty()) {
        worst = current;
        current = (best + worst) / 2;
      } else {
        best = current;
        current = (best + worst) / 2;
        answer = temp;
      }
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
