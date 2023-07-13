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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    typedef ListNode node;
    
    pair<int, node*> __rec__ ( node* root )  {
        if ( root->next ) {
            pair<int, node*> next = __rec__(root->next);
            if ( root->val < next.first ) {
                root->next = nullptr;
                return next;
            } else {
                root->next = next.second;
                return {root->val, root};
            }
        } else {
            return {root->val, root};
        }
    }
    
    ListNode* removeNodes(ListNode* head) {
        pair<int, node*> temp = __rec__(head);
        return temp.second;
    }
};

int main() {

    ios_base::sync_with_stdio(false); 


    return 0;
}

