#include <iostream>
#include <vector>
using namespace std;

template < typename container_type >
void printVector ( vector < container_type > input ) {
    for ( container_type i : input )
        cout << i << " ";
    cout << endl ;
    return;
}