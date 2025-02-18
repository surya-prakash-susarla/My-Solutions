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

  ListNode* removeNthFromEnd(ListNode* head, int n) {
    stack<node*> values;
    for (node* root = head; root; root = root->next) {
      values.push(root);
    }

    if (n == 1) {
      values.pop();
      if (values.empty())
        return nullptr;
      values.top()->next = nullptr;
      return head;
    } else {
      node* ending = nullptr;
      for (int i = n; i; i--) {
        ending = values.top();
        values.pop();
      }
      if (values.empty()) {
        return ending->next;
      } else {
        values.top()->next = ending->next;
        return head;
      }
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
