#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define node TreeNode 

class Solution {
public:
    
    int getVal ( const map<int,int> answer , const int& key ) {
        auto it = answer.find ( key );
        if ( it == answer.end() )   return numeric_limits<int>::min();
        return it->second;
    }
    
    void calc ( node* root , int depth , map<int,int>& answer ) {
        if ( root == NULL )     return;
        answer[depth] = max ( getVal ( answer , depth ) , root->val );
        calc ( root->left , depth+1 , answer );
        calc ( root->right , depth+1 , answer );
    }
    
    vector<int> largestValues(TreeNode* root) {
        map<int,int> answer ;
        calc ( root , 0 , answer );
        vector<int> values ;
        for ( auto it = answer.begin() ; it != answer.end() ; it++ ) 
             values.push_back ( it->second );   
        return values; 
    }
};