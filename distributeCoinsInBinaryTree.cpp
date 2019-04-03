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
    
    pair<int,int> find ( TreeNode* root ) {
        if ( root == NULL )
            return make_pair ( 0 , 0 );
        
        pair<int,int> left_value = find ( root->left );
        pair<int,int> right_value = find ( root->right );
        
        int diff = root->val - 1 + left_value.first + right_value.first ;
        int cost = left_value.second + right_value.second + abs ( diff ) ;
        
        return make_pair ( diff , cost );
        
    }
    
    int distributeCoins(TreeNode* root) {
        return ( find(root) ).second;
    }
};