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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        if ( root == NULL )
            return vector<string>();
        
        vector<string> left = binaryTreePaths ( root->left );
        vector<string> right = binaryTreePaths ( root->right );
        
        string current_value = to_string  ( root->val );
        
        if ( left.size() == 0 and right.size() == 0 )
            return vector<string> { current_value };
        
        vector<string> answers ; 
        for ( string i : left )
            answers.push_back ( current_value + "->" + i );
        for ( string i : right )
            answers.push_back ( current_value + "->" + i );
        
        return answers ;
        
    }
};