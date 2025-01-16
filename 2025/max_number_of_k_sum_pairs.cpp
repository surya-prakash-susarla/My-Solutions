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
    int maxOperations(vector<int>& input, int k) {
        unordered_map<int, int> counts;

        for ( int i : input )
            if ( i <= k )
                counts[i]++;

        int answer = 0;

        for(auto& i: counts) {
            int required = (k-i.first);
            if ( required == i.first ) {
                answer += (i.second / 2);
                i.second %= 2;
            } else {
                if ( counts.find(required) == counts.end() )
                    continue;
                const int current_count = min(i.second, counts[required]);
                i.second -= current_count;
                counts[required] -= current_count;
                answer += current_count;
            }
        }

        return answer;
    }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
