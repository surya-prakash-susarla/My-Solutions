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

  ListNode* addTwoNumbers(ListNode* input1, ListNode* input2) {
    int carry = 0;

    node* left = input1;
    node* right = input2;

    node* answer = nullptr;
    node* head = nullptr;

    while (left or right) {
      int left_value = left ? left->val : 0;
      int right_value = right ? right->val : 0;

      int sum = left_value + right_value + carry;
      int current_digit = sum % 10;
      carry = sum / 10;

      node* new_node = new node(current_digit);

      if (answer)
        answer->next = new_node;

      if (not answer)
        head = new_node;

      answer = new_node;

      if (left)
        left = left->next;
      if (right)
        right = right->next;

      if (not left and not right)
        break;
    }

    if (carry != 0)
      answer->next = new node(carry);

    return head;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
