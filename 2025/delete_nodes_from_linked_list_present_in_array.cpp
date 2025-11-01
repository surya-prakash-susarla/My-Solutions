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
  typedef struct {
    node* prev;
    node* current;
    node* next;
  } marker;

  marker remove(marker x) {
    if (x.prev) {
      node* temp = x.current;
      x.prev->next = x.next;
      x.current = x.next;
      if (x.next)
        x.next = x.next->next;
      else
        x.next = nullptr;
    } else {
      x.current->next = nullptr;
      x.current = x.next;
      if (x.next)
        x.next = x.next->next;
      else
        x.next = nullptr;
    }
    return x;
  }

  marker move(marker x) {
    x.prev = x.current;
    x.current = x.next;
    x.next = (x.next ? x.next->next : nullptr);
    return x;
  }

  ListNode* modifiedList(vector<int>& raw_input, ListNode* root) {
    if (!root)
      return nullptr;

    unordered_set<int> input(raw_input.begin(), raw_input.end());

    marker current;
    current.prev = nullptr;
    current.current = root;
    current.next = root->next;

    node* answer = nullptr;

    int i = 0;
    while (current.current != nullptr) {
      bool contains = input.contains(current.current->val);
      if (!answer and !contains)
        answer = current.current;
      if (contains) {
        current = remove(current);
      } else {
        current = move(current);
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
