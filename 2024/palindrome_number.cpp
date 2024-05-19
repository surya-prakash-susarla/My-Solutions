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
    bool isPalindrome(int x) {
        if ( x < 0 )
            return false;
        if ( x == 0 )
            return true;
        
        long long int rev = 0;
        for ( int i = x , tp = floor(log10(x)) ; i ; i/=10, tp-- )
            rev += (i%10) * pow(10, tp);

        return rev == x;
    }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
