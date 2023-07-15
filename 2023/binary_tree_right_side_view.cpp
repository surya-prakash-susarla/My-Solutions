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
    vector<int> rightSideView(TreeNode* root) {
        if ( root == nullptr )
            return {};
        
        typedef vector<int> vint;
        typedef TreeNode node;

        vint answer;
        queue<node*> current;
        current.push(root);

        while ( not current.empty() ) {
            answer.push_back(current.back()->val);
            queue<node*> next;
            while ( not current.empty() ) {
                node* temp = current.front();
                current.pop();
                if ( temp->left )
                    next.push(temp->left);
                if ( temp->right )
                    next.push(temp->right);
            }
            swap(current, next);
        }

        return answer;
    }
};

int main() {

    ios_base::sync_with_stdio(false); 


    return 0;
}

