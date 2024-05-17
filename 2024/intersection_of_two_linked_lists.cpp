#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  typedef ListNode node;

  inline int len(node* root) {
    int answer = 0;
    for (; root; root = root->next)
      answer++;
    return answer;
  }

  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int alen = len(headA);
    int blen = len(headB);

    if (alen > blen) {
      for (int movedist = alen - blen; movedist > 0; movedist--)
        headA = headA->next;
    } else if (blen > alen) {
      for (int movedist = blen - alen; movedist > 0; movedist--)
        headB = headB->next;
    }

    for (; headA; headA = headA->next, headB = headB->next)
      if (headA == headB)
        return headA;

    return nullptr;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
