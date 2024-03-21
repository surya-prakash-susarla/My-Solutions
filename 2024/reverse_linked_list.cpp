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
  ListNode* reverseList(ListNode* head) {
    typedef ListNode node;
    if (not head)
      return nullptr;

    vector<node*> values;
    node* root = head;
    while (root) {
      values.push_back(root);
      root = root->next;
    }

    values[0]->next = nullptr;

    for (int i = 1; i < values.size(); i++)
      values[i]->next = values[i - 1];

    return *values.rbegin();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
