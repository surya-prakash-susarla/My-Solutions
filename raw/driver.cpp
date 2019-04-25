#include <iostream>
#include <vector>
#include "DebugMethods.h"
#include "Djikstra.h"

using namespace std;

void DjikstraDriver () {
    
    // Djikstra test driver 
    vector<vector<int>>graph {
                    {-1, 4, -1, -1, -1, -1, -1, 8, -1}, 
                    {4, -1, 8, -1, -1, -1, -1, 11, -1}, 
                    {-1, 8, -1, 7, -1, 4, -1, -1, 2}, 
                    {-1, -1, 7, -1, 9, 14, -1, -1, -1}, 
                    {-1, -1, -1, 9, -1, 1-1, -1, -1, -1}, 
                    {-1, -1, 4, 14, 1-1, -1, 2, -1, -1}, 
                    {-1, -1, -1, -1, -1, 2, -1, 1, 6}, 
                    {8, 11, -1, -1, -1, -1, 1, -1, 7}, 
                    {-1, -1, 2, -1, -1, -1, 6, 7, -1} 
    }; 
    vector<int> solution {0,4,12,19,21,11,9,8,14};
    int source  = 0 ;
    vector<int> return_value = djikstraSourceAllPairShortestPath ( source , graph );
    cout << "Djikstra outputs : " << endl ;
    cout << "Returned value : " ;
    printVector<int> ( return_value );
    cout << "Expected value : " ;
    printVector<int> ( solution );

    if ( solution == return_value )
        cout << "TEST PASSED SUCCESFULLY" << endl ;
    else 
        cout << "TEST FAILED" << endl ;

    return ;
}   

int main () {
    DjikstraDriver ();
}