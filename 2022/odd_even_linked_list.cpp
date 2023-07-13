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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    typedef ListNode node;
    if (not head)
      return nullptr;
    node* odd = head;
    node* even = head ? head->next : nullptr;
    node* init_even = even;
    node* odd_end = nullptr;
    while (odd and even) {
      odd->next = odd->next ? odd->next->next : nullptr;
      even->next = even->next ? even->next->next : nullptr;
      odd_end = odd;
      odd = odd->next;
      even = even->next;
    }

    if (odd)
      odd_end = odd;

    odd_end->next = init_even;

    return head;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
