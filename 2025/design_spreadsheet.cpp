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

class Spreadsheet {
 public:
  vector<vector<int>> values;
  Spreadsheet(int rows) {
    values = vector<vector<int>>(rows + 1, vector<int>(26, 0));
  }

  pair<int, int> get_loc(const string& ref) {
    int col = ref[0] - 'A';
    int row = stoi(ref.substr(1, ref.size()));
    return make_pair(row, col);
  }

  void setCell(string cell, int value) {
    pair<int, int> loc = get_loc(cell);
    values[loc.first][loc.second] = value;
  }

  void resetCell(string cell) {
    pair<int, int> loc = get_loc(cell);
    values[loc.first][loc.second] = 0;
  }

  bool is_loc(string ref) { return ref[0] >= 'A' and ref[0] <= 'Z'; }

  int get_value(string x) {
    // cout << "getting value for : " << x << endl;
    if (is_loc(x)) {
      // cout << "treating as location" << endl;
      pair<int, int> ref = get_loc(x);
      return values[ref.first][ref.second];
    } else {
      return stoi(x);
    }
  }

  int getValue(string input) {
    int plus_loc = 0;
    for (; plus_loc < input.size(); plus_loc++) {
      if (input[plus_loc] == '+') {
        break;
      }
    }
    string x = input.substr(1, plus_loc - 1);
    string y = input.substr(plus_loc + 1, input.size());

    return get_value(x) + get_value(y);
  }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */©leetcode

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
