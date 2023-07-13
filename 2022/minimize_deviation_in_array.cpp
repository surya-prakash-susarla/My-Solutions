#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void __print__(priority_queue<int, vector<int>, less<int>> values) {
    cout << "printing values" << endl;
    while (!values.empty()) {
      cout << values.top() << " ";
      values.pop();
    }
    cout << endl;
    return;
  }

  int minimumDeviation(vector<int>& nums) {
    set<int> temp(nums.begin(), nums.end());
    priority_queue<int, vector<int>, less<int>> values;

    int minvalue = numeric_limits<int>::max();
    for (int i : temp) {
      int current_value = i % 2 == 1 ? i * 2 : i;
      values.push(current_value);
      minvalue = min(minvalue, current_value);
    }

    // cout << "final values before starting stuff : " << endl;
    // __print__(values);

    // cout << "initial minvalue : " << minvalue << endl;

    int answer = values.top() - minvalue;

    // cout << "values.top() : " << values.top() << endl;
    // cout << "initial answer value : " << answer << endl ;

    while (values.top() % 2 == 0) {
      answer = min(answer, values.top() - minvalue);

      // cout << "updated answer value : " << answer << endl;

      int current = values.top() / 2;
      values.pop();
      values.push(current);
      minvalue = min(minvalue, current);

      // cout << "after current run values are : " << endl;
      // __print__(values);
    }

    answer = min(answer, values.top() - minvalue);

    return answer;
  }
};
