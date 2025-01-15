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
  typedef struct _trans {
    string name;
    int time;
    int value;
    string loc;
    string og;
    bool is_fraud = false;

    void print() {
      cout << name << ", " << time << ", " << value << ", " << loc << endl;
    }
  } trans;

  trans get_value(const string& ref) {
    vector<int> locs;
    int counter = 3;
    for (int i = 0; i < ref.size() and counter; i++) {
      if (ref[i] == ',') {
        locs.push_back(i);
        counter--;
      }
    }

    trans temp;
    temp.name = ref.substr(0, locs[0]);
    temp.time = stoi(ref.substr(locs[0] + 1, locs[1] - locs[0]));
    temp.value = stoi(ref.substr(locs[1] + 1, locs[2] - locs[1]));
    temp.loc = ref.substr(locs[2] + 1, locs.size());
    temp.og = ref;

    return temp;
  }

  vector<string> invalidTransactions(vector<string>& input) {
    unordered_map<string, vector<trans>> values;

    for (const string& i : input) {
      trans current = get_value(i);
      // current.print();

      if (current.value > 1000) {
        current.is_fraud = true;
      }

      for (trans& prev : values[current.name]) {
        if (prev.loc != current.loc && abs(current.time - prev.time) <= 60) {
          prev.is_fraud = true;
          current.is_fraud = true;
        }
      }

      values[current.name].emplace_back(current);
    }

    vector<string> answer;

    for (auto i : values)
      for (auto j : i.second)
        if (j.is_fraud)
          answer.emplace_back(j.og);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
