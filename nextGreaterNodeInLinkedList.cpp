#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define node ListNode 

class Solution {
public:
    
    vector<int> answer ;
    
    void calc ( node* root , int depth ) {
        if ( root == NULL ) {
            answer.resize ( depth , 0 );
            return;   
        }
        calc ( root->next , depth+1 );
        node* temp = root ;
        while ( temp != NULL ) {
            if ( temp->val > root->val ) {
                answer[depth] = temp->val ;
                break ;
            }
            temp = temp->next ;
        }
        return;
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        calc ( head , 0 );
        return answer ;
    }
};