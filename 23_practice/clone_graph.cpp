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

  vector<node*> memo;

  void add_if_not_exists(node* rec, node* to_add) {
    bool exists = false;
    for (node* n : rec->neighbors)
      if (n == to_add) {
        exists = true;
        break;
      }
    if (not exists) {
      // cout << "adding reverse neighbor : " << rec->val << " " << to_add->val
      // << endl;
      rec->neighbors.push_back(to_add);
    }
  }

  node* __rec__(node* orig) {
    if (memo[orig->val] != nullptr) {
      // cout << "found pre-existing node : " << orig->val << endl;
      return memo[orig->val];
    } else {
      node* temp = new node(orig->val);
      memo[orig->val] = temp;
      // cout << "create node : " << temp->val << endl;
      for (node* n : orig->neighbors) {
        node* new_n = __rec__(n);
        // cout << "adding neighbor : " << temp->val << " " << new_n->val <<
        // endl; temp->neighbors.push_back(new_n);
        add_if_not_exists(temp, new_n);
        add_if_not_exists(new_n, temp);
      }
      return temp;
    }
  }

  Node* cloneGraph(Node* root) {
    if (root == nullptr)
      return nullptr;
    memo = vector<node*>(101, nullptr);
    return __rec__(root);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
