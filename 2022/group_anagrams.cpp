#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& values) {
    unordered_map<string, vector<string>> pat;

    for (const string& i : values) {
      string temp(i);
      sort(temp.begin(), temp.end());
      pat[temp].push_back(i);
    }

    vector<vector<string>> answer;
    for (const pair<string, vector<string>>& i : pat) {
      answer.emplace_back(i.second);
    }

    return answer;
  }
};

int main() {
  return 0;
}
