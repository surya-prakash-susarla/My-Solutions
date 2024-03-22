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
  bool isPalindrome(ListNode* head) {
    typedef ListNode node;
    vector<node*> temp;
    node* root = head;
    while (root) {
      temp.push_back(root);
      root = root->next;
    }
    vector<node*> temp2 = temp;
    reverse(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++) {
      if (temp[i]->val != temp2[i]->val)
        return false;
    }
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
