#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    if (root == nullptr)
      return {};

    typedef vector<int> vint;

    typedef Node node;

    vector<vector<int>> answer;
    queue<node*> current;

    current.push(root);

    while (not current.empty()) {
      queue<node*> next;
      vint current_level;
      while (not current.empty()) {
        current_level.push_back(current.front()->val);
        for (node* temp : current.front()->children)
          next.push(temp);
        current.pop();
      }
      if (not current_level.empty())
        answer.emplace_back(current_level);
      swap(current, next);
    }

    return answer;
  }
};

int main() {
  return 0;
}
