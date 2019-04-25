#include <iostream>
#include <vector>
#include "DebugMethods.h"
#include "Djikstra.h"
#include "CustomHeap.h"

using namespace std;

bool compare ( vector<int> a , vector<int> b ) {
    if ( a[0] < b[0] )
        return false; 
    else if ( a[0] == b[0] and a[1] < b[1] )
        return false;
    return true;
}

void CustomHeapDriver() {
    CustomHeap<vector<int>> temp  ( compare );
    
    vector<vector<int>> solution { 
        {5,20,30},
        {10,15,30},
        {10,20,30}
    };

    vector<vector<int>> answer;

    temp.push ( vector<int> { 10,20,30 } );
    temp.push ( vector<int> { 5,20,30 } );
    temp.push ( vector<int> { 10,15,30 } );

    while ( not temp.empty() ) {
        answer.push_back ( temp.top() );
        temp.pop();
    }

    if ( answer == solution )
        cout << "Custom Heap test passed "<< endl ;
    else 
        cout << "Custom heap test failed" << endl ;

    return;
}

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
        cout << "Djikstra test passed " << endl ;
    else 
        cout << "Djikstra test failed " << endl ;

    return ;
}   

int main () {
    DjikstraDriver ();
}