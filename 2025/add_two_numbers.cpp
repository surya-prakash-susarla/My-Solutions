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

  ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
    node* answer = nullptr;
    node* answer_head = nullptr;

    int extra = 0;

    while (a or b) {
      int a_dig = (a != nullptr ? a->val : 0);
      int b_dig = (b != nullptr ? b->val : 0);

      int sum_val = a_dig + b_dig + extra;

      extra = (sum_val / 10);
      sum_val %= 10;

      node* current = new node();
      current->val = sum_val;

      if (answer_head) {
        answer_head->next = current;
        answer_head = current;
      } else {
        answer_head = current;
        answer = current;
      }

      if (a)
        a = a->next;
      if (b)
        b = b->next;
    }

    if (extra) {
      node* current = new node();
      current->val = extra;
      answer_head->next = current;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
