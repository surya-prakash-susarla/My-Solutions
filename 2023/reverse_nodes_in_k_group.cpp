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

  optional<node*> get_next_start(node* root, int n) {
    node* temp = root;
    for (int i = 0; i < n; i++) {
      if (not temp)
        return nullopt;
      temp = temp->next;
    }
    return temp;
  }

  node* rev_and_get_start(node* root, int n) {
    stack<node*> temp;
    for (int i = 0; i < n; i++, root = root->next)
      temp.push(root);

    node* top = temp.top();
    temp.pop();
    node* current = top;
    while (not temp.empty()) {
      current->next = temp.top();
      temp.pop();
      current = current->next;
    }

    return top;
  }

  node* __rec__(node* start, int n) {
    optional<node*> next = get_next_start(start, n);
    if (not next.has_value()) {
      return start;
    } else {
      node* new_start = rev_and_get_start(start, n);
      node* next_seg = __rec__(*next, n);
      start->next = next_seg;
      return new_start;
    }
  }

  ListNode* reverseKGroup(ListNode* head, int k) { return __rec__(head, k); }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
