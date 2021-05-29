#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <utility>
#include <map>
#include <stack>
#include <memory>
#include <cmath>
#include <set>
#include <queue>

// Problem: 

typedef long long int llint;
typedef long double ldouble;

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
    
    using tn = TreeNode;
    
    int __rec__ ( tn* node , int count ) {
        if ( !node )    return count; 
        count++ ; 
        int lc = __rec__ ( node->left , count );
        int rc = __rec__ ( node->right , count );
        return max ( lc , rc );
    }
    
    int maxDepth(TreeNode* root) {
        return __rec__ ( root , 0 );
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    
    return 0;
}
