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

class CBTInserter {
public:
    
    node* root = NULL ;
    
    CBTInserter(TreeNode* rootValue) {
        this->root = rootValue ;
    }
    
    int insert(int v) {
        queue<node*> nodes ;
        nodes.push ( this->root );
        bool inserted = false ;
        while ( not inserted ) {
            queue<node*> childNodes ;
            while ( not nodes.empty() ) {
                node* currentNode = nodes.front() ;
                if ( currentNode->left == NULL ) {
                    currentNode->left = new node ( v );
                    inserted  = true ;
                    return currentNode->val ;
                }
                else    childNodes.push ( currentNode->left );
                if ( currentNode->right == NULL ) {
                    currentNode->right = new node ( v );
                    inserted = true;
                    return currentNode->val ;
                }
                else    childNodes.push ( currentNode->right );
                nodes.pop();
            }
            nodes = childNodes;
        }
        return -1 ;
    }
    
    TreeNode* get_root() {
        return this->root ;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */