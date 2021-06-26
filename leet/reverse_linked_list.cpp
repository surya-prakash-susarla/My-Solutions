#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem:

typedef long long int llint;
typedef long double ldouble;

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
  using node = ListNode;
  ListNode* reverseList(ListNode* head) {
    node* current = head;
    node* prev = nullptr;
    node* temp = nullptr;

    while (current) {
      temp = current;
      current = temp->next;
      temp->next = prev;
      prev = temp;
    }

    return prev;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
