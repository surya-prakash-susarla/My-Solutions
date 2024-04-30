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

  node* rev(node* start, int count) {
    if (not start)
      return nullptr;
    node* prev = start;
    node* current = start->next;
    for (int i = 1; i < count; i++) {
      node* next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    start->next = current;
    return prev;
  }

  ListNode* reverseBetween(ListNode* head, int left, int right) {
    node* root = head;
    for (int i = 1; i < left - 1; i++)
      root = root->next;
    if (left == 1)
      return rev(root, right - left + 1);
    root->next = rev(root->next, right - left + 1);
    return head;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
