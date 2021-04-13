#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <utility>
#include <map>
#include <stack>
#include <memory>
#include <cmath>
#include <set>
#include <queue>

// Problem: 

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for ( int i=0 ; i<nums.size() ; i++ ) {
            if ( nums[i] < target )   continue ;
            else if ( nums[i] >= target )   return i ;
        }
        return nums.size();
    }
};

int main(){
  std::ios_base::sync_with_stdio(false);
  
  return 0;
}
