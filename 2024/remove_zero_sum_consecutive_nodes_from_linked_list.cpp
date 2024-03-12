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

  pair<bool, node*> find(node* head) {
    int current = head->val;
    node* end = head->next;
    while (end) {
      if (current == 0)
        return {true, end};

      current += end->val;
      end = end->next;
    }
    if (current == 0)
      return {true, nullptr};

    return {false, nullptr};
  }

  ListNode* removeZeroSumSublists(ListNode* head) {
    // Special processing if the first subsequence starts at the head.
    {
      bool first_seq_remove = true;
      while (first_seq_remove and head) {
        auto result = find(head);
        if (result.first)
          head = result.second;
        else
          first_seq_remove = false;
      }
    }

    if (head == nullptr)
      return nullptr;

    node* answer = head;

    // Since 'head' is now stabilized proceed with the rest of the subsequences.
    node* parent = head;
    node* next = head->next;
    while (next) {
      auto result = find(next);
      if (result.first) {
        parent->next = result.second;
        next = result.second;
      } else {
        parent = next;
        next = next->next;
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
