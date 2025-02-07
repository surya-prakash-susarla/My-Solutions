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
    int function_id;
    string action;
    int timestamp;
    int other_time;
  } logline;

  logline parse(const string& input) {
    const int first_sep = input.find(':');

    logline value;
    const string function_id = input.substr(0, first_sep);
    // cout << "function id : " << function_id << endl;
    value.function_id = stoi(function_id);

    const int second_sep = input.find(':', first_sep + 1);
    const string action =
        input.substr(first_sep + 1, second_sep - first_sep - 1);
    // cout << "action : " << action << endl;
    value.action = action;

    const string timestamp = input.substr(second_sep + 1);
    // cout << "timestamp : " << timestamp << endl;
    value.timestamp = stoi(timestamp);

    return value;
  }

  vector<int> exclusiveTime(int n, vector<string>& logs) {
    stack<logline> values;

    vector<int> answer(n, 0);

    for (const string& i : logs) {
      logline current = parse(i);
      if (current.action == "start") {
        values.push(current);
      } else {
        logline prev = values.top();
        values.pop();
        int time = (current.timestamp - prev.timestamp + 1 - prev.other_time);

        answer[current.function_id] += time;

        if (not values.empty()) {
          logline earlier_exe = values.top();
          values.pop();
          earlier_exe.other_time += (time + prev.other_time);
          values.push(earlier_exe);
        }
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
