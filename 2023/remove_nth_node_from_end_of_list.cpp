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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr)
      return nullptr;

    typedef ListNode node;
    vector<node*> nodes;
    for (node* temp = head; temp; temp = temp->next)
      nodes.emplace_back(temp);

    auto it = next(nodes.rbegin(), n - 1);
    auto it_after = next(it, -1);
    auto it_before = next(it, 1);

    node* node_before = it_before == nodes.rend() ? nullptr : *it_before;
    node* node_after =
        distance(nodes.rbegin(), it_after) < 0 ? nullptr : *it_after;

    if (not node_before)
      return node_after;

    node_before->next = node_after;
    return head;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
