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
    
    node* next ( node* val ) {
        if ( val == NULL )  return NULL ;
        return val->next ;
    }
    
    ListNode* oddEvenList(ListNode* head) {
        node *io , *ie , *no , *ne , *to ;
        io = head ;
        ie = next ( head ) ;
        no = next ( ie ) ;
        ne = ie ;
        
        while ( no != NULL ){ 
            to = next ( no->next );
            io->next = no ;
            io = no ;
            ne->next = no->next ;
            ne = ne->next;
            no->next = ie ;
            no = to ;
        }
        
        return head;
    }
};