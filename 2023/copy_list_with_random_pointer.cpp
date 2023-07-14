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

  Node* copyRandomList(Node* head) {
    unordered_map<node*, node*> mapping;
    node* new_head = nullptr;

    {
      node* root = head;
      node* answer = nullptr;
      node* first = nullptr;
      while (root) {
        node* nn = new node(root->val);
        if (answer)
          answer->next = nn;
        if (not first)
          first = nn;
        answer = nn;
        mapping[root] = nn;
        root = root->next;
      }
      new_head = first;
    }

    {
      node* root = head;
      node* temp = new_head;
      while (root) {
        if (root->random)
          temp->random = mapping[root->random];
        root = root->next;
        temp = temp->next;
      }
    }

    return new_head;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
