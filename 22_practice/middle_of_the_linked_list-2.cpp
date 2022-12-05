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
  ListNode* middleNode(ListNode* head) {
    typedef ListNode node;

    node* first = head;
    node* second = head;
    node* answer = head;

    while (first and second) {
      if (second->next == nullptr) {
        break;
      }
      second = second->next;
      if (second)
        second = second->next;
      first = first->next;
    }

    answer = first;

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
