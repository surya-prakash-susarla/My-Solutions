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

  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    node* left = l1;
    node* right = l2;

    node* answer = nullptr;
    node* answer_base = nullptr;
    int carry_value = 0;

    while (true) {
      int left_digit = left ? left->val : 0;
      int right_digit = right ? right->val : 0;
      int sum = left_digit + right_digit + carry_value;
      int sum_base = sum % 10;
      carry_value = sum / 10;

      node* answer_current = new node(sum_base);
      if (answer) {
        answer->next = answer_current;
        answer = answer_current;
      } else {
        answer_base = answer_current;
        answer = answer_current;
      }

      if (left)
        left = left->next;
      if (right)
        right = right->next;

      if (not left and not right)
        break;
    }

    if (carry_value != 0)
      answer->next = new node(carry_value);

    return answer_base;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
