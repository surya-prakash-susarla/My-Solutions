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
  typedef vector<int> vint;

  vint get_digs(int n) {
    vint a;
    for (; n > 0; n /= 10) {
      // cout << "looping : " << n << endl;
      a.push_back(n % 10);
    }
    reverse(a.begin(), a.end());
    return a;
  }

  int maximumSwap(int n) {
    vint digs = get_digs(n);

    // cout << "digs : " << endl;
    // for ( int i : digs )    cout << i << " ";
    // cout << endl;

    for (int i = 0; i < digs.size(); i++) {
      int cmax = digs[i];
      int cind = i;
      for (int j = i + 1; j < digs.size(); j++) {
        if (digs[j] != digs[i] and digs[j] >= cmax and j > cind) {
          cmax = digs[j];
          cind = j;
        }
      }
      if (cind != i) {
        // cout << "swapping : " << digs[i] << " , " << digs[cind] << endl;
        swap(digs[i], digs[cind]);
        break;
      }
    }

    // cout << "digs : " << endl;
    // for ( int i : digs )    cout << i << " ";
    // cout << endl;

    int answer = 0;
    for (int i : digs)
      answer = ((answer * 10) + i);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
