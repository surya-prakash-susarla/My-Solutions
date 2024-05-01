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
  typedef ListNode node;

  node* __rec__(const vector<node*>& lists) {
    node* answer = nullptr;
    node* answer_current = nullptr;

    int count = lists.size();
    vector<node*> heads = lists;

    while (count) {
      int minvalue = INT_MAX;
      auto minit = heads.end();
      for (auto it = heads.begin(); it != heads.end(); it++) {
        if (*it and (*it)->val < minvalue) {
          minvalue = (*it)->val;
          minit = it;
        }
      }
      if (minit == heads.end())
        break;

      if (answer_current) {
        answer_current->next = *minit;
        answer_current = answer_current->next;
      } else {
        answer_current = *minit;
        answer = answer_current;
      }

      *minit = (*minit)->next;
      if (*minit == nullptr)
        count--;
    }

    return answer;
  }

  ListNode* mergeKLists(vector<ListNode*>& lists) { return __rec__(lists); }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
