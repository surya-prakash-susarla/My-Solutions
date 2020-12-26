#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
 public:
  typedef Node* node;
  typedef pair<node, node> pairs;

  pairs main_(node start, node current) {
    node next_node = current->next;
    if (current->child) {
      // flatten child tree and attach in the middle
      pairs flat_child = main_(current->child, current->child);
      current->child = nullptr;
      current->next = flat_child.first;
      flat_child.first->prev = current;
      if (next_node) {
        flat_child.second->next = next_node;
        next_node->prev = flat_child.second;
      }
    }
    if (next_node)
      return main_(start, next_node);
    return pairs(start, current);
  }

  Node* flatten(Node* head) {
    if (!head)
      return nullptr;
    return main_(head, head).first;
  }
};