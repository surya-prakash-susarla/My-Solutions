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

class Solution {
 public:
  typedef TreeNode node;

  int countNodes(TreeNode* root) {
    int answer = 0;

    if (root == nullptr)
      return answer;

    queue<node*> nodes;
    nodes.push(root);

    while (not nodes.empty()) {
      node* current = nodes.front();
      answer++;

      nodes.pop();
      if (current->left)
        nodes.push(current->left);
      if (current->right)
        nodes.push(current->right);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
