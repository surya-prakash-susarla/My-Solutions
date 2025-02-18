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
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
 public:
  typedef Node node;

  map<node*, node*> mapping;

  node* root = nullptr;

  node* get(node* source) {
    if (source == nullptr)
      return nullptr;

    if (mapping[source])
      return mapping[source];

    node* temp = new node(source->val);
    mapping[source] = temp;
    return temp;
  }

  node* copy(node* head) {
    if (head == nullptr)
      return nullptr;

    node* current = get(head);
    if (root == nullptr)
      root = current;
    current->random = get(head->random);
    current->next = copy(head->next);
    return current;
  }

  Node* copyRandomList(Node* head) {
    copy(head);
    return root;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
