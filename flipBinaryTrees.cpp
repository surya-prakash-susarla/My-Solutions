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
    
    int assign ( TreeNode* a ) {
        if ( a == NULL )
            return -1;
        return a->val;
    }
    
    int swap ( TreeNode* a , TreeNode* b ) {
        int a_left = assign(a->left),
            a_right = assign(a->right),
            b_left = assign(b->left),
            b_right = assign(b->right);
        if ( a_left == b_left and a_right == b_right )
            return 0 ;
        if ( a_left == b_right and a_right == b_left )
            return 1;
        return -1;
    }
    
    bool flipEquiv(TreeNode* a, TreeNode* b ) {
        if ( a == NULL and b == NULL )
            return true;
        if ( a == NULL or b == NULL )
            return false;
        int swap_dec = swap ( a , b );
        if ( swap_dec == -1 )   
            return false;
        else if ( swap_dec == 1 ) {
            TreeNode* temp = b->left ;
            b->left = b->right ;
            b->right = temp ;
        }
        return flipEquiv ( a->left , b->left ) and flipEquiv ( a->right , b->right );
    }
};