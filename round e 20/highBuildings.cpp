#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

typedef long long int llint ;




vector<llint> __calc__ (void) {
	llint n , a, b ,c ; 
	cin >> n >> a >> b >> c ; 

	llint only_a = a - c ;
	llint only_b = b - c ;
	llint empty = n - ( only_a + only_b + c ) ; 	
	
	


	return vector<llint>();
}

void __print__ ( const vector<llint>& answer ) {
	if ( answer.empty() ){
		cout << "IMPOSSIBLE" ; 
		return;
	}
	for ( size_t i=0 ; i<answer.size() ; i++ ){
		cout << answer[i] ;
		if ( i < answer.size() -1 ) 
			cout << endl;
	}
	return;
}


int main() {
	llint t;
	cin >> t; 
	for ( llint i=1 ; i<=t ; i++ ){
		vector<llint> answer = __calc__ () ; 
		cout << "Case #" << i << ": " ; 
		__print__ ( answer ) ; 
		if ( i < t  )
			cout << endl ;;
	}
	return 0;
}
