#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef unsigned long long int llint ;

class trie {
    public:
    char value ;
    bool end_node = true; 
    vector<trie*> links ;

    trie(char c){
        this->value = c;
    }

    int index ( char c ) {
        for ( int i=0 ; i<this->links.size() ; i++ )
            if ( this->links[i]->value == c )
                return i;
        return -1;
    }

    trie* insert ( char c ) {
        this->end_node = false ;
        int index_value = this->index(c);
        if ( index_value != -1 )    return this->links[index_value];
        trie* temp = new trie(c);
        this->links.push_back(temp);
        return temp ;
    }
};

void insert ( trie* root , string value ) {
    trie* iter = root ;
    for ( int i=0 ; i<value.size() ; i++ ) {
        int index = iter->index(value[i]);
        if ( index != -1 and iter->links[index]->end_node ) return;
        else    iter = iter->insert(value[i]);
    }
    if ( not iter->end_node ) {
        iter->links.clear();
        iter->end_node = true ;
    }
    return;
}

void makeStrings ( trie* root , string value , vector<string> &values ) {
    value = value+root->value ;
    if ( root->end_node ) {
        values.push_back ( value.substr(1) );
        return;
    }
    for ( int i=0 ; i<root->links.size() ; i++ )
        makeStrings ( root->links[i]  , value , values );
    return;
}

llint calc () {
    llint n , k ;
    cin >> n >> k ;
    llint total_values = 1 ;
    total_values = total_values << n ;
    trie* root = new trie('@');
    for ( llint i=0 ; i<k ; i++ ){
        string temp ;
        cin >> temp ;
        insert ( root , temp );
    }
    vector<string> final_values ; 
    makeStrings ( root , "" , final_values );
    for ( string temp : final_values ){
        llint shift = n - temp.size() , t = 1; 
        t = t<< shift ;
        total_values = total_values - t;
    }
    return total_values ;
}

int main() {
    llint t ;
    cin >> t; 
    for ( llint j=1 ; j<=t ; j++ ) {
        llint answer = calc() ;
        cout << "Case #" << j << ": " << answer << endl;
    }
    return 0;
}