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
  ListNode* oddEvenList(ListNode* head) {
    typedef ListNode node;

    node* estart = nullptr;
    node* ostart = nullptr;
    node* ecurrent = nullptr;
    node* ocurrent = nullptr;

    node* current = head;
    node* temp = nullptr;

    for (int i = 0; current; i++) {
      temp = current->next;
      if (i % 2 == 0) {
        if (ecurrent)
          ecurrent->next = current;
        ecurrent = current;
        if (not estart)
          estart = ecurrent;
      } else {
        if (ocurrent)
          ocurrent->next = current;
        ocurrent = current;
        if (not ostart)
          ostart = ocurrent;
      }
      current = temp;
    }

    if (ecurrent)
      ecurrent->next = nullptr;

    if (ocurrent)
      ocurrent->next = nullptr;

    if (not estart)
      return nullptr;

    node* eend = estart;
    for (; eend->next; eend = eend->next)
      ;

    eend->next = ostart;
    return estart;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
