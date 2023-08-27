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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  bool hasCycle(ListNode* root) {
    typedef ListNode node;

    if (root == nullptr)
      return false;

    node* temp = root;
    node* temp2 = root;

    while (true) {
      temp = temp->next;
      if (temp == nullptr)
        return false;
      temp2 = temp2->next;
      if (temp2 == nullptr)
        return false;
      temp2 = temp2->next;
      if (temp2 == nullptr)
        return false;
      if (temp == temp2)
        return true;
    }

    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
