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
    if (not head)
      return nullptr;

    int id = 0;
    map<node*, int> original_ids;
    for (node* temp = head; temp; temp = temp->next)
      original_ids[temp] = id++;

    map<int, node*> copy_ids;
    node* new_root = nullptr;
    node* new_head = nullptr;
    for (node* temp = head; temp; temp = temp->next) {
      if (new_head) {
        Node* current = new Node(temp->val);
        new_head->next = current;
        new_head = new_head->next;
        copy_ids[original_ids[temp]] = current;
      } else {
        new_head = new Node(temp->val);
        new_root = new_head;
        copy_ids[original_ids[temp]] = new_head;
      }
    }

    node* temp = nullptr;
    node* temp2 = nullptr;
    for (temp = head, temp2 = new_root; temp;
         temp = temp->next, temp2 = temp2->next) {
      if (temp->random)
        temp2->random = copy_ids[original_ids[temp->random]];
    }

    return new_root;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
