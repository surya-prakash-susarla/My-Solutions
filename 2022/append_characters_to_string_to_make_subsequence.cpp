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
    int appendCharacters(string input, string value) {
        int ii = 0 , vi = 0;
        
        for ( ; ii < input.size() and vi < value.size() ; ) { 
            if ( input[ii] == value[vi] )  {
                vi++;
            } 
            ii++;
        }
        
        if ( vi == value.size() )   return 0;
        else return value.size()  - vi ;
    }
};

int main() {

    ios_base::sync_with_stdio(false); 


    return 0;
}

