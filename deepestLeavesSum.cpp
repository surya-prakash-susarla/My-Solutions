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
    typedef TreeNode* node;
    
    int main_ ( node root ){
        if ( !root )    return 0;
        queue<node> current;
        // init 
        int sum = 0;
        current.push(root);
        
        while ( not current.empty() ){
            queue<node> children;
            sum = 0;
            while ( not current.empty() ){
                node i = current.front();
                sum += i->val;
                if ( i->right ) children.push(i->right);
                if ( i->left )  children.push(i->left);
                current.pop();
            }
            current = children;
        }
        return sum;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        return main_ ( root );
    }
};