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
    bool canMakeArithmeticProgression(vector<int>& values) {

        if ( values.size() < 2 )
            return true;
         
        sort(values.begin(), values.end());


        int diff = values[1] - values[0];

        for ( int i=2 ; i<values.size() ; i++ )
            if ( values[i] - values[i-1] != diff )
                return false;
        
        return true;
    }
};

int main() {

    ios_base::sync_with_stdio(false); 


    return 0;
}

