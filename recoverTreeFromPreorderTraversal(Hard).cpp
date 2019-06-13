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
    
    node* make ( int startIndex , int stopIndex , const vector<int>& values , const vector<int>& depths ) {
        if ( startIndex >= stopIndex )  
            return NULL;
        node* root = new node ( values[startIndex] );
        root->left = NULL ;
        root->right = NULL ; 
        if ( startIndex+1 == values.size() or depths[startIndex+1] != depths[startIndex]+1 )   
            return root ;
        int rightChild = -1 ;
        for ( int i=startIndex+2 ; i<stopIndex ; i++ ) 
            if ( depths[i] == depths[startIndex]+1 ) {
                rightChild = i ;
                break; 
            }
        if ( rightChild == -1 )
            root->left = make ( startIndex+1 , stopIndex , values , depths );
        else {
            root->left = make ( startIndex+1 , rightChild , values , depths );
            root->right = make ( rightChild , stopIndex , values , depths );
        }
        return root ;
    }
    
    TreeNode* recoverFromPreorder(string input) {
        int depth = 0 , i = 0 ; 
        vector<int> values , depths ;
        while ( i < input.size() ) {
            if ( input[i] == '-' ) depth++;
            else{
                int start = i ;
                while ( i < input.size() and input[i] != '-' )  i++;
                values.push_back ( stoi(input.substr ( start , i-start ) ) );
                i-=1;
                depths.push_back  ( depth );
                depth = 0;
            }
            i++;
        }
        return make ( 0 , values.size() , values , depths );
    }
};