#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> primes = {};

    vector<int> smallest_prime_factor ( n+1 , -1 );

    for ( int i=2 ; i<n ; i++ ){
        if ( smallest_prime_factor[i] == -1 ){
            primes.push_back ( i );
            smallest_prime_factor[i] = i;  
        }

        for ( int j=0 ; j<primes.size() && i * primes[j] <= n ; j++ )
            smallest_prime_factor[i*primes[j]] = primes[j];

    }

    cout << "Primes in the limit : " << endl;
    for ( int i : primes )
        cout << i << " ";
    cout << endl ;


    return 0;

}