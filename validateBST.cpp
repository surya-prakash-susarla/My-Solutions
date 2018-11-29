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
    
    bool check ( TreeNode* root , int left_limit , int right_limit ){
        if ( root == NULL ) return true;
        if ( left_limit != -1 and root->val <= left_limit )  return false;
        if ( right_limit != -1 and root->val >= right_limit )   return false;
        if ( root->left != NULL and not check ( root->left , left_limit , root->val ) ) return false;
        if ( root->right != NULL and not check ( root->right , root->val , right_limit ) )  return false;
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        if ( root == NULL ) return true;
        return check( root->left , -1 , root->val ) and check ( root->right , root->val , -1 );
    }
};