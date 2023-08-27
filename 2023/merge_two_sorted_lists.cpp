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
  ListNode* mergeTwoLists(ListNode* temp1, ListNode* temp2) {
    typedef ListNode node;
    node* root = nullptr;
    node* head = nullptr;
    while (temp1 and temp2) {
      if (temp1->val < temp2->val) {
        if (root) {
          root->next = temp1;
          root = root->next;
        } else {
          root = temp1;
          head = temp1;
        }
        temp1 = temp1->next;
      } else {
        if (root) {
          root->next = temp2;
          root = root->next;
        } else {
          root = temp2;
          head = temp2;
        }
        temp2 = temp2->next;
      }
    }

    for (; temp1; temp1 = temp1->next) {
      if (root) {
        root->next = temp1;
        root = root->next;
      } else {
        root = temp1;
        head = root;
      }
    }

    for (; temp2; temp2 = temp2->next) {
      if (root) {
        root->next = temp2;
        root = root->next;
      } else {
        root = temp2;
        head = root;
      }
    }

    return head;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
