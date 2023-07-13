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
  ListNode* swapNodes(ListNode* head, int k) {
    typedef ListNode node;

    int n = 0;
    {
      node* temp = head;
      while (temp) {
        n++;
        temp = temp->next;
      }
    }

    node* first = nullptr;

    {
      int current = 0;
      node* temp = head;
      while (temp) {
        current++;
        if (current == k) {
          first = temp;
          break;
        }
        temp = temp->next;
      }
    }

    node* second = nullptr;

    {
      int current = 0;
      k = n - k + 1;
      node* temp = head;
      while (temp) {
        current++;
        if (current == k) {
          second = temp;
          break;
        }
        temp = temp->next;
      }
    }

    swap(first->val, second->val);

    return head;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
