#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
using namespace std;
typedef long long int llint;

llint __calc__()
{
    llint size;
    cin >> size;
    if ( size == 1 )   return 0;
    vector<llint> values(size);
    for (llint i = 0; i < size; i++)
        cin >> values[i];

    llint answer = 0 ;
    for ( llint i=1 ; i<values.size() ; i++ ){
        if ( values[i] > values[i-1] ){
            values[i] = 1;
        } else if ( values[i] < values[i-1] ){
            values[i] = -1;
        } else {
            values[i] = 0;
        }
    }

    llint h = 0 , n = 0;
    for ( llint i=1 ; i<values.size() ; i++ ){
        if ( values[i] == 1 ) {
            h+=1 ;
            n = 0;
        } else if ( values[i] == -1 ){
            n -=1 ;
            h = 0;
        }
        if ( h > 3 || n > 3 ){
            answer+=1 ; 
            h = 0 ;
            n = 0 ; 
            i += 1;
        }
    }
    return answer;
}

int main()
{
    llint t;
    cin >> t;
    for (llint i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": " << __calc__();
        if (i < t)
            cout << endl;
    }
    return 0;
}