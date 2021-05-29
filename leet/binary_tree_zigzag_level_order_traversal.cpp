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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)  return {};
        
        using vint = vector<int>;
        using vvint = vector<vint> ;
        using tn = TreeNode;
        stack<tn*> ns;
        stack<tn*> cs;
                
        ns.push(root);
        
        bool ltr = true;
        vvint answer;
        while(!ns.empty()){
            cs = std::move(ns);
            vint cvals;
            while ( !cs.empty() ){
                tn* top = cs.top();
                cvals.push_back ( top->val );
                if(ltr){
                    if (top->left)  ns.push(top->left);
                    if (top->right) ns.push(top->right);
                } else {
                    if (top->right) ns.push(top->right);
                    if (top->left) ns.push(top->left);
                }
                cs.pop();
            }
            ltr = !ltr;
            answer.push_back(std::move(cvals));
        }
        return answer;
    }
};

int main(){
  std::ios_base::sync_with_stdio(false);
  
  return 0;
}
