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
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> values;
        map<int, int> counts;

        typedef vector<int> vint;

        for(const vint& i: matches) {
            values.insert(i[0]);
            values.insert(i[1]);
            counts[i[1]]++;
        }

        vector<vint> answer(2);

        for ( int i : values ) {
            auto it = counts.find(i);
            if ( it == counts.end() ) answer[0].push_back(i);
            else if ( it->second == 1 ) answer[1].push_back(i);
        }

        return answer;
    }
};

int main() {

    ios_base::sync_with_stdio(false); 


    return 0;
}

