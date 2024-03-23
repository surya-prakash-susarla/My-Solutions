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
  void reorderList(ListNode* head) {
    typedef ListNode node;

    vector<node*> temp1;
    for (node* root = head; root; root = root->next)
      temp1.push_back(root);

    if (temp1.size() < 2)
      return;

    vector<node*> temp2 = temp1;
    reverse(temp2.begin(), temp2.end());

    int n = temp1.size() / 2;

    node* current = nullptr;

    for (int i = 0; i < n; i++) {
      if (current)
        current->next = temp1[i];

      current = temp1[i];
      current->next = temp2[i];
      current = temp2[i];
    }

    if (temp1.size() % 2 == 1) {
      current->next = temp1[n];
      current = current->next;
    }

    current->next = nullptr;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
