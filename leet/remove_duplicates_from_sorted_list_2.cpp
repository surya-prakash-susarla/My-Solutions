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
    ListNode* deleteDuplicates(ListNode* head) {
        if ( head == nullptr || head->next == nullptr )
            return head;
        
        ListNode* target = head ; 
        
        while ( target != nullptr && target->val == head->val )
            target = target->next ;
        
        if ( target == head->next ) {
            head->next = deleteDuplicates(target);
            return head;
        } else {
            return deleteDuplicates(target);
        }
        
    }
};

int main(){
  std::ios_base::sync_with_stdio(false);
  
  return 0;
}
