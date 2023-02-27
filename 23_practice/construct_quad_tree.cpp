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
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
 public:
  typedef Node node;
  typedef vector<int> vint;
  typedef vector<vint> vvint;
  typedef pair<int, int> pint;

  inline bool are_equal(const vector<node*>& values) {
    if (not values[0]->isLeaf)
      return false;
    int value = values[0]->val;

    for (int i = 1; i < values.size(); i++)
      if (not values[i]->isLeaf or value != values[i]->val)
        return false;

    return true;
  }

  node* __rec__(pint v, pint h, const vvint& values) {
    int n = (v.second - v.first) + 1;

    if (n == 1) {
      return new Node(values[v.first][h.first] == 1, true);
    }

    int cutoff = n / 2;
    int vc = v.first + cutoff;
    int hc = h.first + cutoff;

    const pint vh1 = make_pair(v.first, vc - 1);
    const pint vh2 = make_pair(vc, v.second);

    const pint hh1 = make_pair(h.first, hc - 1);
    const pint hh2 = make_pair(hc, h.second);

    // top left
    node* tl = __rec__(vh1, hh1, values);
    // top right
    node* tr = __rec__(vh1, hh2, values);
    // bottom left
    node* bl = __rec__(vh2, hh1, values);
    // bottom right
    node* br = __rec__(vh2, hh2, values);

    if (are_equal({tl, tr, bl, br})) {
      return new Node(tl->val, true);
    } else {
      return new Node(/*default_value=*/0, false, tl, tr, bl, br);
    }
  }

  Node* construct(vector<vector<int>>& grid) {
    const pint starting_range = make_pair(0, grid.size() - 1);
    return __rec__(starting_range, starting_range, grid);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
