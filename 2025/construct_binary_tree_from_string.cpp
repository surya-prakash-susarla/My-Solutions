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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  typedef TreeNode node;

  node* __rec__(int start, int end, const string& input) {
    if (start >= end)
      return nullptr;

    // cout << "substring : " << input.substr(start, end-start) << endl;

    int vend = start;
    for (; vend < end; vend++) {
      if (input[vend] == '(' or input[vend] == ')') {
        break;
      }
    }

    int value = stoi(input.substr(start, vend - start));
    node* current = new node(value);
    if (input[vend] == ')') {
      return current;
    }

    int count = 1;
    int lend = vend + 1;
    for (; lend < end; lend++) {
      if (input[lend] == '(')
        count++;
      else if (input[lend] == ')')
        count--;
      if (count == 0)
        break;
    }

    node* left = __rec__(vend + 1, lend, input);

    node* right = nullptr;
    if (lend != end) {
      right = __rec__(lend + 2, end - 1, input);
    }

    current->left = left;
    current->right = right;
    return current;
  }

  TreeNode* str2tree(string s) { return __rec__(0, s.size(), s); }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
