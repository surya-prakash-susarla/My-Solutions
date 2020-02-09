#include <bits/stdc++.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    typedef TreeNode *node;

    void getSumOfGrandChildren(node root, int &sum)
    {
        if (root->left)
        {
            if (root->left->left)
                sum += root->left->left->val;
            if (root->left->right)
                sum += root->left->right->val;
        }
        if (root->right)
        {
            if (root->right->right)
                sum += root->right->right->val;
            if (root->right->left)
                sum += root->right->left->val;
        }
    }

    void main_(node root, int &sum)
    {
        if (!root)
            return;
        if (root->val % 2 == 0)
            getSumOfGrandChildren(root, sum);
        main_(root->left, sum);
        main_(root->right, sum);
    }

    int sumEvenGrandparent(TreeNode *root)
    {
        int sum = 0;
        main_(root, sum);
        return sum;
    }
};