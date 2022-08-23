#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    typedef vector<int> vint;
    typedef list<int> lint;

    int high = -1;
    int low = -1;

    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] >= x) {
        high = i;
        low = i - 1;
        break;
      }
    }

    if (high == -1) {
      high = arr.size();
      low = arr.size() - 1;
    }

    lint temp;
    while (k) {
      if (high == arr.size()) {
        temp.push_front(arr[low--]);
      } else if (low < 0) {
        temp.push_back(arr[high++]);
      } else {
        int left_dist = abs(x - arr[low]);
        int right_dist = abs(x - arr[high]);
        if (left_dist < right_dist) {
          temp.push_front(arr[low--]);
        } else if (right_dist < left_dist) {
          temp.push_back(arr[high++]);
        } else {
          temp.push_front(arr[low--]);
        }
      }
      k--;
    }

    return {temp.begin(), temp.end()};
  }
};
