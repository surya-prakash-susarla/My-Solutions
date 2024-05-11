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

class NumArray {
 public:
  NumArray(vector<int>& nums) {
    original_values = nums;
    tree = vector<int>(4 * original_values.size(), -1);
    n = original_values.size();
    build_tree(0, n - 1, 0);

    cout << "contents of tree : " << endl;
    for (int i : tree)
      if (i != -1)
        cout << i << " ";
    cout << endl;
  }

  int build_tree(int left, int right, int node_num) {
    if (left == right) {
      tree[node_num] = original_values[left];
    } else {
      int mid = (left + right) / 2;
      tree[node_num] = build_tree(left, mid, 2 * node_num + 1) +
                       build_tree(mid + 1, right, 2 * node_num + 2);
    }
    return tree[node_num];
  }

  void update_rec(int left,
                  int right,
                  int original_index,
                  int diff,
                  int node_num) {
    if (original_index < left or original_index > right)
      return;

    tree[node_num] += diff;

    if (left < right) {
      int mid = (left + right) / 2;
      update_rec(left, mid, original_index, diff, 2 * node_num + 1);
      update_rec(mid + 1, right, original_index, diff, 2 * node_num + 2);
    }
  }

  void update(int index, int val) {
    int diff = val - original_values[index];
    original_values[index] = val;
    update_rec(0, n - 1, index, diff, 0);
  }

  int sum_rec(int left,
              int right,
              int range_left,
              int range_right,
              int node_num) {
    if (left > right or range_left > range_right)
      return 0;

    if (range_left <= left and range_right >= right)
      return tree[node_num];

    int mid = (left + right) / 2;
    return sum_rec(left, mid, range_left, min(mid, range_right),
                   2 * node_num + 1) +
           sum_rec(mid + 1, right, max(mid + 1, range_left), range_right,
                   2 * node_num + 2);
  }

  int sumRange(int left, int right) {
    return sum_rec(0, n - 1, left, right, 0);
  }

  int n = 0;
  vector<int> tree;
  vector<int> original_values;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
