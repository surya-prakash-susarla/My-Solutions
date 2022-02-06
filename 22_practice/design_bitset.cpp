#include <bits/stdc++.h>

using namespace std;



class Bitset {
public:
    Bitset(int size) {
        bsize = size ;
    }
    
    void fix(int idx) {
        if ( is_following_set ){
            values.insert(idx);
        } else {
            auto it = values.find(idx);
            if ( it != values.end() )
                values.erase(it);
        }
    }
    
    void unfix(int idx) {
        if ( !is_following_set ){
            values.insert(idx);
        } else {
            auto it = values.find(idx);
            if ( it != values.end() )
                values.erase(it);
        }
    }
    
    void flip() {
        is_following_set = not is_following_set;
    }
    
    bool all() {
        return is_following_set ? values.size() == bsize : values.size() == 0;
    }
    
    bool one() {
        return is_following_set ? values.size() > 0 : values.size() < bsize ;
    }
    
    int count() {
        return is_following_set ? values.size() : (bsize - values.size());
    }
    
    string toString() {
        if (is_following_set) {
            string answer ( bsize , '0' );
            for ( int i : values )  answer[i] = '1';
            return answer;
        } else {
            string answer ( bsize , '1' );
            for ( int i : values )  answer[i] = '0';
            return answer;
        }
    }
    
    
    int bsize ;
    bool is_following_set = true ;
    unordered_set<int> values;
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */