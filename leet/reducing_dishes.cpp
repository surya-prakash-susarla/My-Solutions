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

using namespace std;

typedef long long int llint;
typedef long double ldouble;

template<typename T>
using vec = std::vector<T>;

// Problem : https://leetcode.com/problems/reducing-dishes/

class Solution {
public:
    int maxSatisfaction(vector<llint>& values) {
    vec<std::pair<llint,llint>> memo ( values.size() , {0 /*total value including multiplier*/ ,0 /*sum of all values from here*/} );

	std::sort ( values.begin() , values.end() );

	llint pos_ind = -1 ; 
	for ( llint i=0 ; i<values.size() ; i ++ )
		if ( values[i] >0 ) {
			pos_ind = i ; 
			break;
		}
	
	if ( pos_ind == -1 )
	// if all are negative numbers then no point in going forward, just return 0.
		return 0 ;
	
	// since the value will certainly include all positive values in the fold, we only go backwards into the negative end to see if that helps. 
	// calculate first positive value and then use that rec for all backward calculations.

	for ( llint i = pos_ind, j=1 ; i<values.size() ; i++, j++ ) {
		memo[pos_ind].first += values[i] * j ;
		memo[pos_ind].second += values[i];
	}

	llint best_value = memo[pos_ind].first ;

	if ( pos_ind == 0 )
	// since no neg return the current value.
		return best_value;

	for ( llint i=pos_ind -1 ; i >-1 ; i-- ) {
		memo[i].first = memo[i+1].first + memo[i+1].second + values[i] ;
		memo[i].second = memo[i+1].second + values[i];
		best_value = std::max ( best_value, memo[i].first );
	}

	return best_value; 
    }
};

int main(){
    llint n;
    std::cout << "Enter the count : " << std::endl;
	std::cin >> n;
    vec<llint> values(n);
	std::cout << "Enter the values : " << std::endl;
	for ( llint i=0 ; i<n ; i++ )
		std::cin >> values[i];
    Solution temp;
	llint answer = temp.maxSatisfaction(values);
	std::cout << "Answer : " << answer << std::endl;
    return 0;
}
