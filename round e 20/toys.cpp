#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <numeric>
#include <limits>

typedef long long int llint;
typedef std::pair<llint,llint> toy;
constexpr llint INDEF = std::numeric_limits<llint>::max();
constexpr toy DELETED_TOY = {std::numeric_limits<llint>::min(), std::numeric_limits<llint>::min()};

toy __rec__ ( std::vector<toy> values , llint c_value , llint deleted ) {

	llint first_fail = -1 ;

	for ( llint i=0 ; i<values.size() ; i++ )
		if ( values[i] != DELETED_TOY && values[i].second > c_value - values[i].first ) {
			first_fail = i ;
			break;
		}

	if ( first_fail == -1 )
		return { deleted , INDEF };

	llint current_max_time = c_value ;
	std::for_each ( values.begin() , values.begin() + first_fail , [&](const toy& current ){
			if ( current != DELETED_TOY )
				current_max_time += current.first ;
				});
	
	llint updated_c_value = c_value - values[first_fail].first ;
	values[first_fail] = DELETED_TOY;

	toy res_toy = DELETED_TOY;
	if ( values.size() - deleted > 1 )
		res_toy = __rec__ ( values , updated_c_value , deleted+1 );
	
	return current_max_time > res_toy.second ? toy{deleted, current_max_time} : res_toy ;

}

toy __calc__ () {
	llint n; 
	std::cin >> n;
	std::vector<toy> values ( n );

	for ( toy &i : values )
		std::cin >> i.first >> i.second ;

	llint cumulative_value = 0 ;
	std::for_each ( values.begin() , values.end() , [&](const toy& value){
			cumulative_value += value.first ;
			});

	return __rec__ ( values , cumulative_value , 0 ) ;

}

void __print__ ( const toy& answer ) {
	std::cout << answer.first << " " ;
	if ( answer.second == INDEF ) std::cout << "INDEFINITELY";
	else std::cout << answer.second ;
	return;
}

int main(){
	llint t;
	std::cin >> t;
	for ( llint i=1 ; i<=t ; i++ ){
		toy answer = __calc__ () ;
		std::cout << "Case #" << i << ": " ;
		__print__ ( answer ) ;
		if ( i < t )
			std::cout << std::endl;
	}
	return 0;
}
