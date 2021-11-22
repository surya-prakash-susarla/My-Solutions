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
    using node = TreeNode;
    
    void __find_and_delete__(node* root, int key) {
        if ( root == nullptr ){
            cout << "SOMETHING WENT WRONG";
            return;
        }
        if ( key < root->val ) {
            if ( !root->left )  {return;} 
            if ( key == root->left->val ) {
                root->left = __delete_node__(root->left);
                return;
            } else {
                __find_and_delete__(root->left, key);
                return;
            }
        } else {
            if ( !root->right ) {return;}
            if ( key == root->right->val ) {
                root->right = __delete_node__(root->right);
                return;
            } else {
                __find_and_delete__(root->right, key);
                return;
            }
        }
    }
    
    
    node* __delete_node__(node* root){
        if ( root->right == nullptr and root->left == nullptr ) return nullptr ;
        if ( root->left == nullptr )    return root->right ;
        if ( root->right == nullptr )   return root->left ;
        
        node* ln = root->left ; 
        node* target = root->right ; 
        node* mv = target->left ;
        
        // cout << "mv target val : " << mv->val;
        
        target->left = ln ; 
        
        if ( mv != nullptr ) {
            node* loc = ln ; 
            while ( loc->right != nullptr ) loc = loc->right ;
            loc->right = mv ;
        }
        
        return target;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if ( !root )    return nullptr;
        else if ( root->val == key ) return __delete_node__(root);
        else { __find_and_delete__(root, key); return root; }
    }
};
 
 int main(){
   std::ios_base::sync_with_stdio(false);
   
   return 0;
 }
 