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
  int removeStones(vector<vector<int>>& stones) {
    typedef struct final {
      int count = 0;
      set<int> x;
      set<int> y;
    } gdata;

    map<int, gdata> groups;

    int index = 0;

    for (const vector<int>& i : stones) {
      vector<int> options;
      for (pair<const int, gdata>& j : groups) {
        if (j.second.x.find(i[0]) != j.second.x.end() or
            j.second.y.find(i[1]) != j.second.y.end()) {
          options.push_back(j.first);
        }
      }
      if (options.empty()) {
        gdata temp;
        temp.count = 1;
        temp.x.insert(i[0]);
        temp.y.insert(i[1]);
        groups[index++] = temp;
      } else {
        gdata final_updated;
        final_updated.count = 1;
        final_updated.x.insert(i[0]);
        final_updated.y.insert(i[1]);
        // cout << "performing union of stuff: " << endl;
        for (int j : options) {
          gdata temp = groups[j];
          final_updated.count += temp.count;
          final_updated.x.insert(temp.x.begin(), temp.x.end());
          final_updated.y.insert(temp.y.begin(), temp.y.end());

          // cout << "index : " << j << endl;
          // cout << "count : " << temp.count << endl;
          // cout << "x values : " << endl;
          // for ( int k : temp.x )  cout << k << " ";
          // cout << endl;
          // cout << "y values : " << endl;
          // for ( int k : temp.y )  cout << k << " ";
          // cout << endl;

          groups.erase(j);
        }

        // cout << "final count value : " << final_updated.count << endl;
        // cout << "final x values : " << endl;
        // for ( int k : final_updated.x ) cout << k << " ";
        // cout << endl;
        // cout << "final y values : " << endl;
        // for ( int k : final_updated.y ) cout << k << " ";
        // cout << endl;

        groups[index++] = final_updated;
      }
    }

    int answer = 0;
    for (const pair<int, gdata>& i : groups) {
      answer += (i.second.count - 1);

      // cout << "index : " << i.first << endl;
      // cout << "count : " << i.second.count << endl;
      // cout << "x values : " << endl;
      // for ( int j : i.second.x )  cout << j << " ";
      // cout << endl;
      // cout << "y values : " << endl;
      // for ( int j : i.second.y )  cout << j << " ";
      // cout << endl;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
