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
  int minMeetingRooms(vector<vector<int>>& intervals) {
    typedef vector<int> vint;
    typedef vector<vint> vvint;

    sort(intervals.begin(), intervals.end(), [](const vint& a, const vint& b) {
      if (a[0] == b[0])
        return a[1] < b[1];
      return a[0] < b[0];
    });

    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> booked_rooms;

    for (int i = 0; i < intervals.size(); i++) {
      // cout << "current interval : " << intervals[i][0] << " , " <<
      // intervals[i][1] << endl;

      // prune rooms that were vacated before current instant;
      while (not booked_rooms.empty() and
             booked_rooms.top() <= intervals[i][0]) {
        // cout << "popping room booked at instant : " << booked_rooms.top() <<
        // endl;
        booked_rooms.pop();
      }

      booked_rooms.push(intervals[i][1]);

      answer = max(answer, (int)booked_rooms.size());
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
