#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string input) {
        map<char,int> values ;
        for ( char i : input )
            values[i] += 1 ;
        
        // cout << "freq : " << endl ;
        // for ( auto i = values.begin() ; i != values.end() ; i++ )
        //     cout << i->first << " " << i->second << endl ;
        // cout << endl ;
        
        map<int, vector<char> > convert ;
        for ( auto it = values.begin() ; it != values.end() ; it++ )
            convert[it->second].push_back  (it->first);
        
        // cout << "converted freqs : " << endl ;
        // for ( auto i = convert.rbegin() ; i != convert.rend() ; i++ ) {
        //     cout << "FREQ : " << i->first ; 
        //     for ( auto j : i->second )  cout << j << " " ;
        //     cout << endl ;
        // }
        
        string answer ; 
        for ( auto it = convert.rbegin() ; it != convert.rend() ; it++ )
            for ( char i : it->second )
                answer = answer + string ( it->first , i );
        return answer ;
    }
};