/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    vector<TreeNode*> make ( int n , vector<vector<TreeNode*> >& memo , vector<bool>& memo_valid) {
        if ( n == 1 )
            return vector<TreeNode*> ( 1 , new TreeNode(0) );
        
        if ( memo_valid[n] )
            return memo[n];
        
        vector<TreeNode*> answer; 
        n-=1;
        for ( int i=1 ; i<= n/2 ; i+=2 ){
            vector<TreeNode*> left = make ( i , memo , memo_valid );
            vector<TreeNode*> right = make ( n-i , memo , memo_valid );
            for ( int k=0 ; k<left.size() ; k++ )
                for ( int j=0 ; j<right.size() ; j++ ) {
                    TreeNode* unswap = new TreeNode(0);
                    unswap->left = left[k];
                    unswap->right = right[j];
                    TreeNode* swap = NULL;
                    if ( i!=n/2 ) {
                        swap = new TreeNode(0);
                        swap->left = unswap->right;
                        swap->right = unswap->left;
                    }
                    answer.push_back ( unswap );
                    if ( swap != NULL )
                        answer.push_back ( swap );
                }
            
        }
        memo[n] = answer;
        memo_valid[n] = true;
        return answer;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        // since root always makes odd number of nodes to even 
        if ( n == 1 )   return vector<TreeNode*> (1, new TreeNode(0) );
        vector<vector<TreeNode*> > memo ( n , vector<TreeNode*> ( 1, NULL ) );
        vector<bool> memo_valid ( n , false );
        return make ( n , memo , memo_valid );
    }
};