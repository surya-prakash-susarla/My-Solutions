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

  ListNode* reverseBetween(ListNode* head, int left, int right) {
    node* lprev = nullptr;
    node* rnext = nullptr;

    {
      int current = 1;
      for (node* temp = head; temp; temp = temp->next, current++) {
        if (current == left - 1) {
          lprev = temp;
        } else if (current == right + 1) {
          rnext = temp;
        }
      }
    }

    node* inner_head = nullptr;
    node* inner_end = nullptr;

    {
      // reversal core.
      node* lcurrent = lprev ? lprev->next : head;
      stack<node*> nodes;
      for (int index = left; index != right + 1; index++) {
        nodes.push(lcurrent);
        lcurrent = lcurrent->next;
      }
      // reverse things.
      inner_head = nodes.top();
      inner_end = nodes.top();
      node* current = nodes.top();
      nodes.pop();
      while (not nodes.empty()) {
        current->next = nodes.top();
        current = nodes.top();
        inner_end = current;
        nodes.pop();
      }
      inner_end->next = nullptr;
    }

    if (lprev)
      lprev->next = inner_head;
    if (rnext)
      inner_end->next = rnext;

    return lprev ? head : inner_head;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
