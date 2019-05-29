#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 *
*/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    int numComponents( ListNode* head, vector<int>& temp ) {
        int answer = 0 ; 
        set<int> values ( temp.begin() , temp.end() );
        bool prev = false ;
        while ( head != NULL ) {
            auto findVal = values.find ( head->val ) ;
            if ( findVal == values.end() ) {
                prev = false ;
            }
            else {
                values.erase ( findVal );
                if ( not prev ) answer += 1 ;
                prev = true ;
            }
            head = head->next ;
        }
        return answer ;
    }
};