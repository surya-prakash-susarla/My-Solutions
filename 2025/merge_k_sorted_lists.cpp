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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    typedef ListNode node;
    typedef pair<int, node*> item;

    auto sort_item = [](const item& a, const item& b) -> bool {
      return a.first > b.first;
    };

    typedef priority_queue<item, vector<item>, decltype(sort_item)> store_type;

    store_type store;

    for (node* i : lists) {
      if (i) {
        // cout << "inserting : " << i->val << endl;
        store.push({i->val, i});
      }
    }

    auto print_value = [](store_type temp) {
      for (; not temp.empty(); temp.pop()) {
        cout << temp.top().first << " ";
      }
      cout << endl;
    };

    // {
    //     cout << "printing values from store" << endl;
    //     print_value(store);
    // }

    node* answer_head = nullptr;
    node* answer = nullptr;

    while (not store.empty()) {
      item top = store.top();
      // cout << "current item : " << top.first << endl;
      store.pop();
      if (answer) {
        answer->next = top.second;
        answer = answer->next;
      } else {
        answer = top.second;
        answer_head = answer;
      }
      if (top.second->next) {
        node* next = top.second->next;
        // cout << "next element found : " << next->val << endl;
        store.push({next->val, next});
      } else {
        // cout << "no next element in this element" << endl;
      }

      // cout << "values after this iteration : " << endl;
      // print_value(store);
    }

    return answer_head;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
