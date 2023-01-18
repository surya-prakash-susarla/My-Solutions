#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <utility>
#include <limits>
#include <queue>
#include <cmath>
#include <list>
#include <string>
#include <cstdio>
#include <numeric>
#include <stack>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& values) {
        typedef vector<int> vint;
        vint rev(values.size(), 0);
        int n = values.size();
        rev[n-1] = values[n-1] > 0 ? values[n-1] : 0;
        {
            int cumsum = values[n-1];
            for(int i=n-2 ; i>-1 ; i--) {
                cumsum += values[i];
                rev[i] = max(cumsum, rev[i+1]);
            }
        }
        int answer = numeric_limits<int>::min();
        {
            int cumsum = 0;
            int unskipped = 0;
            for(int i=0 ; i<values.size() ; i++ ) {
                // forward integration upto the current point.
                cumsum = max(cumsum + values[i] , values[i] );
                unskipped += values[i];
                answer = max(answer, cumsum);

                if ( i+2 < values.size() )
                    answer = max(answer, unskipped + rev[i+2] );
            }
        }

        return answer;
    }
};

int main() {

    ios_base::sync_with_stdio(false); 


    return 0;
}

