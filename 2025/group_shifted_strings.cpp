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
  int dist(char source, char target) {
    // cout << "distance between : " << source << " , target : " << target <<
    // endl;
    if (source < target) {
      int answer = target - source;
      // cout << "answer : " << answer << endl;
      return answer;
    } else {
      int answer = ('z' - source) + (target - 'a') + 1;
      // cout << "answer : " << answer << endl;
      return answer;
    }
  }

  vector<int> distances(string s) {
    vector<int> answer;
    answer.push_back(0);
    for (int i = 1; i < s.size(); i++) {
      answer.push_back(dist(s[0], s[i]));
    }
    return answer;
  }

  vector<vector<string>> groupStrings(vector<string>& input) {
    map<vector<int>, vector<string>> values;

    vector<string> single_char_group;

    for (string i : input) {
      if (i.size() == 1)
        single_char_group.push_back(i);
      else
        values[distances(i)].push_back(i);
    }

    vector<vector<string>> answer;
    if (not single_char_group.empty())
      answer.emplace_back(single_char_group);

    for (auto i : values)
      answer.emplace_back(i.second);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
