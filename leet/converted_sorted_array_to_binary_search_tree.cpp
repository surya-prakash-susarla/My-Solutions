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
    using vint = vector<int>;
    using node = TreeNode; 
    
    node* __rec__ ( const int l , const int r , const vint& input ) {
        if ( l > r )   { 
            return nullptr ;
        } 
        
        const int cind = (l+r) / 2 ;
        node* root = new node ( input[cind] );
        root->left = __rec__ ( l , cind-1 , input );
        root->right = __rec__ ( cind+1 , r , input );
        return root ;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return __rec__ ( 0 , nums.size()-1 , nums );
    }
};

int main(){
  std::ios_base::sync_with_stdio(false);
  
  return 0;
}
