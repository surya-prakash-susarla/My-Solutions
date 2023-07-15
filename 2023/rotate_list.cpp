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
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr or k == 0)
      return head;

    typedef ListNode node;

    int n = 0;
    for (node* temp = head; temp; temp = temp->next, n++)
      ;

    k %= n;

    if (k == 0)
      return head;

    int jump = n - k;

    node* fullend = nullptr;
    for (fullend = head; fullend->next; fullend = fullend->next)
      ;

    node* end = nullptr;
    for (end = head, jump--; jump > 0; --jump, end = end->next)
      ;

    node* new_head = end->next;

    fullend->next = head;
    end->next = nullptr;

    return new_head;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
