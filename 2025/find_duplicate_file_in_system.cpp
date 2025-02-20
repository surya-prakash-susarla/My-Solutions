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
  typedef struct {
    string path;
    string name;
    string content;
  } file;

  vector<string> split_string(const string& s) {
    vector<string> answer;

    string current;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        answer.emplace_back(current);
        current = "";
      } else {
        current += s[i];
      }
    }

    answer.emplace_back(current);
    return answer;
  }

  file create(const string& s) {
    int i = s.find('(');
    file answer;
    answer.name = s.substr(0, i);
    answer.content = s.substr(i + 1, s.size() - 1);
    return answer;
  }

  vector<file> parse(const string& s) {
    vector<file> answer;
    vector<string> parts = split_string(s);
    const string path = parts[0];
    for (int i = 1; i < parts.size(); i++) {
      file temp = create(parts[i]);
      temp.path = path;
      answer.emplace_back(temp);
    }
    return answer;
  }

  vector<vector<string>> findDuplicate(vector<string>& paths) {
    map<string, vector<file>> files;
    for (const string& i : paths) {
      vector<file> current = parse(i);
      for (file j : current)
        files[j.content].emplace_back(j);
    }

    // cout << "files : " << endl;
    // for ( auto i : files ) {
    //     cout << "content : " << i.first << endl;
    //     cout << "files : " << endl;
    //     for ( auto j : i.second )
    //         cout << (j.path + "/" + j.name) << endl;
    //     cout << endl;
    // }

    vector<vector<string>> answer;
    for (auto i : files) {
      vector<string> values;
      if (i.second.size() < 2)
        continue;
      for (auto j : i.second)
        values.push_back(j.path + "/" + j.name);
      answer.emplace_back(values);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
