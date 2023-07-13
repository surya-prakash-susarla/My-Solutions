#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <utility>
#include <limits>
#include <queue>
#include <cmath>
#include <list>
#include <string>
#include <cstdio>
#include <numeric>
#include <stack>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    typedef TreeNode node;

    bool __find__(node* root, node* second) {
        if ( root == nullptr and second == nullptr )    return true;
        if ( root == nullptr or second == nullptr ) return false;
        if ( root->val != second->val ) return false;
        return __find__(root->left, second->left) and __find__(root->right, second->right);
    }

    bool __rec__(node* root, node* second) {
        if ( root == nullptr )  return false;
        if ( root->val == second->val ) {
            bool return_value = __find__(root, second);
            if ( return_value ) return true;
        }

        return __rec__(root->left, second) or __rec__(root->right, second);
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return __rec__(root, subRoot);
    }
};

int main() {

    ios_base::sync_with_stdio(false); 


    return 0;
}

