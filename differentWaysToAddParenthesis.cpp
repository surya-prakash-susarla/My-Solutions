#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    pair<int,char> findValue ( const pair<int,char>& a , const pair<int,char>& b ) {
        if ( a.second == '+' )  return {a.first + b.first , b.second };
        else if ( a.second == '-' ) return {a.first - b.first , b.second };
        else    return {a.first * b.first , b.second };
        return {-1,'@'};
    }
    
    vector<int> calc ( int index , const vector<pair<int,char>> values , stack<pair<int,char>> stk ){
        if ( index == values.size()-1 ) {
            pair<int,char> final_value = values[index];
            while ( not stk.empty() ) {
                final_value = findValue ( stk.top() , final_value );
                stk.pop();
            }
            return vector<int> ( 1 , final_value.first );
        }
        vector<int> answer ;
        stack<pair<int,char>> temp = stk ;
        temp.push ( values[index] );
        vector<int> excluded = calc ( index+1 , values , temp );
        answer.insert ( answer.end() , excluded.begin() , excluded.end() );
        stk.push(values[index]);
        while ( stk.size() != 1 ) {
            pair<int,char> first = stk.top();
            stk.pop();
            pair<int,char> second = stk.top();
            stk.pop();
            stk.push ( findValue ( second, first ) );
            vector<int> incl = calc ( index+1 , values , stk );
            answer.insert ( answer.end() , incl.begin() , incl.end() );
        }
        return answer ;
    }
    
    vector<int> diffWaysToCompute(string input) {
        vector<pair<int,char>> values ;
        string temp ;
        int index = 0 ;
        while ( index < input.size() ) {
            if ( input[index] >= '0' and input[index] <= '9' )
                temp = temp + input[index];
            else {
                pair<int,char> current = make_pair ( stoi(temp) , input[index] );
                temp = "";
                values.push_back ( current );
            }
            index += 1;
        }
        values.push_back ( {stoi(temp) , '@' } );
        return calc ( 0 , values , stack<pair<int,char>>() );
    }
};