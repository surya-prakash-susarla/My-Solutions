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
    typedef vector<int> vint;
    typedef vector<vint> vvint;

    optional<int> find_row ( int target , const vvint& values ) {
        for ( int i=1 ; i<values.size() ; i++ )
            if ( target < values[i][0] )    
                return i-1;

        int n = values.size();
        int m = values[n-1].size();
        if ( target <= values[n-1][m-1] )
            return n-1;

        return nullopt;
    }

    bool searchMatrix(vector<vector<int>>& input, int target) {
        optional<int> row = find_row ( target, input );
        if ( !row ) return false;

        return binary_search(input[*row].begin(), input[*row].end(), target);
    }
};

int main() {

    ios_base::sync_with_stdio(false); 


    return 0;
}

