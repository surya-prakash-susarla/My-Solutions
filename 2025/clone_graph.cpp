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
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
 public:
  typedef Node node;

  map<int, node*> nodes;

  node* get(int val) {
    if (nodes.contains(val))
      return nodes[val];

    node* temp = new node();
    temp->val = val;
    nodes[val] = temp;
    return temp;
  }

  map<node*, bool> covered;

  node* __rec__(node* root) {
    if (not root)
      return nullptr;

    if (covered[root])
      return get(root->val);

    covered[root] = true;

    node* clone = get(root->val);

    for (node* i : root->neighbors)
      clone->neighbors.push_back(__rec__(i));

    return clone;
  }

  Node* cloneGraph(Node* node) { return __rec__(node); }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
