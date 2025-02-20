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
  vector<int> dailyTemperatures(vector<int>& input) {
    typedef pair<int, int> pint;

    auto compare = [](const pint& a, const pint& b) -> bool {
      if (a.first == b.first)
        return a.second < b.second;
      return a.first > b.first;
    };

    typedef priority_queue<pint, vector<pint>, decltype(compare)> pq;
    pq values;

    auto print = [](pq ref) {
      for (; not ref.empty(); ref.pop()) {
        cout << ref.top().first << " , " << ref.top().second << endl;
      }
    };

    vector<int> answer(input.size(), 0);

    for (int i = 0; i < input.size(); i++) {
      // cout << endl;
      // cout << "current value : " << input[i] << endl;

      for (; not values.empty();) {
        pint top = values.top();
        if (top.first < input[i]) {
          // cout << "found colder day, temp : " << top.first << " , loc : " <<
          // top.second << endl;
          answer[top.second] = (i - top.second);
          values.pop();
        } else {
          // cout << "No colder day found breaking" << endl;
          break;
        }
      }

      values.push(make_pair(input[i], i));
      // cout << "values after current iteration in queue : " << endl;
      // print(values);
    }

    // cout << "no hotter days found for : " << values.size() << " days" <<
    // endl;
    for (; not values.empty(); values.pop())
      answer[values.top().second] = 0;

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
