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

  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    node* ac = nullptr;
    node* head = nullptr;

    auto set_val = [&](node* temp) {
      if (ac) {
        ac->next = temp;
        ac = ac->next;
      } else {
        ac = temp;
        head = ac;
      }
    };

    while (list1 or list2) {
      if (list1 and list2) {
        if (list1->val < list2->val) {
          set_val(list1);
          list1 = list1->next;
        } else {
          set_val(list2);
          list2 = list2->next;
        }
      } else if (list1) {
        set_val(list1);
        list1 = list1->next;
      } else {
        set_val(list2);
        list2 = list2->next;
      }
    }

    return head;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
