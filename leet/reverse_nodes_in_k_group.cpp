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

  int size;

  node* __calc__(node* root) {
    vector<node*> path;
    node* current = nullptr;

    for (current = root; current != nullptr and path.size() < size;
         current = current->next) {
      path.push_back(current);
    }

    if (path.size() == size) {
      for (int i = 1; i < size; i++)
        path[i]->next = path[i - 1];

      if (current != nullptr)
        path[0]->next = __calc__(current);
      else
        path[0]->next = nullptr;

      return path[size - 1];

    } else {
      return root;
    }
  }

  ListNode* reverseKGroup(ListNode* head, int k) {
    size = k;
    return __calc__(head);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
