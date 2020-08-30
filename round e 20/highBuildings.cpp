#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int llint;

llint n , a , b , c ;

constexpr llint A_VISIT = -1 ; 
constexpr llint B_VISIT = -2 ;
constexpr llint INVIS = -3 ;
constexpr llint COMMON = -4 ;

std::vector<llint> __calc__ () {
	std::cin >> n >> a >> b >> c ;
	
	llint only_a = a - c ;
	llint only_b = b - c ;
	llint empty = n - ( a + b + c );

	if ( n - ( only_a + only_b ) > c )
		return std::vector<llint>();
	
	std::vector<llint> answer ( n , COMMON );
	for ( llint i=0 ; i<only_a ; i++ )
		answer[i] = A_VISIT ; 
	for ( llint i=only_b ; i<n ; i++ )
		answer[i] = B_VISIT ;

	llint start_limit = only_a ; 
	llint end_limit = only_b - 1 ;
	
	if ( only_b == n ){
		llint i = end_limit - 1 ; 
		while ( empty-- > 0 )
			answer[i--] = INVIS;
	} else {
		llint i = start_limit + 1 ;
		while ( empty-- > 0 )
			answer[i++ ] = INVIS;
	}

	llint common_height = n ; 
	llint ind_height = n-1 ; 
	llint invis = n-2 ;

	for ( llint &i : answer ){
		if ( i == A_VISIT || i == B_VISIT )
			i = ind_height ;
		else if ( i == COMMON )
			i = common_height ;
		else 
			i = invis ;
	}

	return answer;
}	


void __print__ ( std::vector<llint> answer ) {
	if ( answer.empty() ){
		std::cout << "IMPOSSIBLE" ; 
		return;
	}
	for ( llint i=0 ; i<n ; i++ ){
		std::cout << answer[i] ; 
		if ( i < n-1 )
			std::cout <<  " " ;
	}
	return;
}


int main(){
	llint t;
	std::cin >> t;
	for ( llint i=1 ; i<=t ; i++ ){
		std::vector<llint> answer = __calc__ ();

		std::cout << "Case #" << i << ": " ;	

		__print__ ( answer ) ; 

		if ( i < t )
			std::cout << std::endl;
	}
	return 0;
}
