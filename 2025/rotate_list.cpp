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
  typedef ListNode node;

  ListNode* rotateRight(ListNode* head, int k) {
    if (not head)
      return nullptr;

    int size = 0;
    for (node* temp = head; temp; temp = temp->next, size++)
      ;

    if (size == 1)
      return head;

    if (k > size) {
      k %= size;
    }

    if (k == 0 or k == size) {
      return head;
    }

    int req_pos = (size - k - 1);
    node* new_end = head;
    for (; req_pos; req_pos--, new_end = new_end->next)
      ;

    node* new_begin = new_end->next;
    new_end->next = nullptr;

    node* pre_end = new_begin;
    for (; pre_end->next; pre_end = pre_end->next)
      ;

    pre_end->next = head;
    return new_begin;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
