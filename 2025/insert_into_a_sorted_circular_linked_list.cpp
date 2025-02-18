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

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
 public:
  typedef Node node;

  void solve(node* current, int value) {
    if (current->val <= value and current->next->val > value) {
      node* temp = new node(value);
      temp->next = current->next;
      current->next = temp;
      return;
    } else {
      solve(current->next, value);
    }
  }

  Node* insert(Node* head, int value) {
    if (not head) {
      // empty list.
      node* current = new node(value);
      current->next = current;
      return current;
    } else if (head == head->next) {
      // single list.
      node* current = new node(value);
      current->next = head;
      head->next = current;
      return head;
    } else {
      node* start = nullptr;
      node* end = nullptr;
      bool first_run = true;
      for (node* root = head;; root = root->next) {
        if (not first_run and root == head)
          break;
        first_run = false;
        if (root->val > root->next->val) {
          start = root->next;
          end = root;
        }
      }
      if (start == nullptr) {
        start = head;
        for (node* root = head->next;; root = root->next)
          if (root->next == start) {
            end = root;
            break;
          }
      }

      if (value <= start->val or value >= end->val) {
        node* temp = new node(value);
        end->next = temp;
        temp->next = start;
      } else {
        solve(start, value);
      }

      return head;
    }
    return nullptr;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
