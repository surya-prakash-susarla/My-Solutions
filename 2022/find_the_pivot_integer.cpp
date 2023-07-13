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
    int pivotInteger(int n) {
        if ( n == 1 )   return 1;
        
        
        int total = (n*(n+1))/2;
        
        int sum = 0;
        for ( int i=1 ; i<=n ; i++ ) {
            sum += i;
            if ( sum == (total - sum + i) )   
                return i;
        }
        
        return -1;
    }
};

int main() {

    ios_base::sync_with_stdio(false); 


    return 0;
}

