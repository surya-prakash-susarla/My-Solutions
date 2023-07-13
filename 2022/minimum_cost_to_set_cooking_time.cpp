#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minCostSetTime(int start, int mc, int pc, int target) {
    typedef struct {
      int mins;
      int secs;
    } times;

    times proper;
    proper.mins = target / 60;
    proper.secs = target % 60;

    times machine = proper;
    if (machine.secs <= 39 && machine.mins > 0) {
      --machine.mins;
      machine.secs += 60;
    }

    auto ser = [](const times& time) -> string {
      string min_ser = time.mins > 0 ? to_string(time.mins) : "";
      string sec_ser = (time.secs < 10 && !min_ser.empty())
                           ? "0" + to_string(time.secs)
                           : to_string(time.secs);
      return min_ser + sec_ser;
    };

    string proper_serialized = ser(proper);
    string machine_serialized = ser(machine);

    // cout << "proper serialized : " << proper_serialized << endl;
    // cout << "machine serialized : " << machine_serialized << endl;

    auto cost = [&](string final_value) -> int {
      char current_char = '0' + start;
      int cost = 0;
      for (int i = 0; i < final_value.size(); i++) {
        if (current_char != final_value[i]) {
          current_char = final_value[i];
          cost += mc;
        }
        cost += pc;
      }
      return cost;
    };

    if (proper_serialized == machine_serialized) {
      return cost(machine_serialized);
    } else if (proper_serialized.size() > 4 && machine_serialized.size() > 4) {
      cout << "DAMN" << endl;
      return 0;
    } else if (proper_serialized.size() > 4) {
      return cost(machine_serialized);
    } else {
      return min(cost(proper_serialized), cost(machine_serialized));
    }
  }
};
