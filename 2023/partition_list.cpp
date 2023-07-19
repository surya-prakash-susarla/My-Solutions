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
  ListNode* partition(ListNode* head, int x) {
    typedef ListNode node;

    node* lesser_head = nullptr;
    node* greater_head = nullptr;
    node* lesser_tail = nullptr;
    node* greater_tail = nullptr;

    node* current = head;

    while (current) {
      node* next = current->next;
      if (current->val < x) {
        if (lesser_head) {
          lesser_tail->next = current;
          lesser_tail = current;
        } else {
          lesser_head = current;
          lesser_tail = current;
        }
      } else {
        if (greater_head) {
          greater_tail->next = current;
          greater_tail = current;
        } else {
          greater_head = current;
          greater_tail = current;
        }
      }
      current->next = nullptr;
      current = next;
    }

    if (lesser_head) {
      lesser_tail->next = greater_head;
      return lesser_head;
    } else {
      return greater_head;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
