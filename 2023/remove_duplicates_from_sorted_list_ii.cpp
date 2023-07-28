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

  ListNode* deleteDuplicates(ListNode* head) {
    node* root = nullptr;

    {
      node* last_distinct = nullptr;
      for (node* temp = head; temp;) {
        bool is_unique = true;
        node* nd = nullptr;

        for (nd = temp->next; nd;) {
          if (nd->val == temp->val) {
            is_unique = false;
            nd = nd->next;
          } else {
            break;
          }
        }

        if (is_unique) {
          if (last_distinct) {
            last_distinct->next = temp;
            last_distinct = temp;
          } else {
            root = temp;
            last_distinct = temp;
          }
          last_distinct->next = nullptr;
        }
        temp = nd;
      }
    }

    return root;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
