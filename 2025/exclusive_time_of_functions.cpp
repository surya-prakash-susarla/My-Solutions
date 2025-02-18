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
  typedef struct _call {
    int id;
    int type;
    int time;
    int other_time;

    void print() const {
      cout << "id : " << id << " , type : " << type << " , time : " << time
           << " ,  ot : " << other_time << endl;
    }
  } call;

  call parse(const string& input) {
    int ind = input.find(':');
    string id = input.substr(0, ind);
    int second_ind = input.find(':', ind + 1);
    string type = input.substr(ind + 1, second_ind - ind - 1);
    string time = input.substr(second_ind + 1, input.size());

    // cout << "line : " << input << endl;
    // cout << "call -> id : " << id << " , type : " << type << " , time : " <<
    // time << endl;

    call temp;
    temp.id = stoi(id);
    temp.type = (type == "start" ? 0 : 1);
    temp.time = stoi(time);
    temp.other_time = 0;
    return temp;
  }

  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<call> values;
    for (const string& i : logs)
      values.emplace_back(parse(i));

    vector<int> answer(n, 0);
    stack<call> calls;

    // cout << "starting stack functions" << endl;

    for (const call& i : values) {
      // cout << "current call : " << endl;
      // i.print();
      if (i.type == 1) {
        // cout << "processing removal" << endl;

        call top = calls.top();
        calls.pop();

        // cout << "top : " << endl;
        // top.print();

        int time = i.time - top.time + 1;
        if (not calls.empty())
          calls.top().other_time += time;
        time -= top.other_time;

        // cout << "total calc time for current function : " << time << endl;

        answer[i.id] += time;
      } else {
        calls.push(i);
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
