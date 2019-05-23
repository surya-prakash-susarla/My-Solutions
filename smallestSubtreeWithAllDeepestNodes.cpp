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
    
    pair<node*,int> calc ( node* root , int depth ) {
        if ( root == NULL ) return { NULL, -1 };
        pair<node*,int> left_value = calc ( root->left , depth + 1 );
        pair<node*,int> right_value = calc ( root->right , depth+1 );
        
        int max_depth = max( left_value.second , right_value.second );
        if ( max_depth == -1 )  return {root,depth};
        if ( left_value.second == max_depth and right_value.second == max_depth )   return {root,max_depth};
        if ( left_value.second == max_depth )   return {left_value.first , max_depth};
        if ( right_value.second == max_depth )  return {right_value.first , max_depth};
        return { NULL , -1 };
    }
    
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        auto answer = calc ( root, 0);
        return answer.first ;
    }
};