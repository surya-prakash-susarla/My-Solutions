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

    int __calc__ ( node* root ) {
        queue<node*> current;
        current.push(root);

        int maxvalue = numeric_limits<int>::min();
        int index = -1;
        int cindex = 1;

        while ( not current.empty() ) {
            queue<node*> next;
            int csum = 0;
            while ( not current.empty() ) {
                node* temp = current.front();
                current.pop();

                csum += temp->val;
                if ( temp->left )   next.push(temp->left);
                if ( temp->right )  next.push(temp->right);

            }

            if ( csum > maxvalue ) {
                maxvalue = csum ; 
                index = cindex;
            }

            cindex++;
            swap ( current, next );
        }

        return index;
    }

    int maxLevelSum(TreeNode* root) {
        return __calc__(root);
    }
};

int main() {

    ios_base::sync_with_stdio(false); 


    return 0;
}

