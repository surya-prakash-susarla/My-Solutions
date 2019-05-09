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
    
    int setWeight ( node* root , int prev_sum ) {
        if ( root == NULL )
            return prev_sum;
        int right_sum = setWeight ( root->right , prev_sum );
        root->val += right_sum ;
        int left_sum = setWeight ( root->left , root->val );
        return left_sum ;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        setWeight ( root , 0 );
        return root ;
    }
};