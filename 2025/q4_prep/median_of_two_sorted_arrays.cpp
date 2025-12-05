class Solution {
 public:
  double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    int ia = 0;
    int ib = 0;

    int total_size = a.size() + b.size();

    int mid_location = -1;
    bool get_next = false;

    if (total_size % 2) {
      mid_location = total_size / 2;
    } else {
      mid_location = (total_size / 2) - 1;
      get_next = true;
    }

    auto move_indices = [&]() {
      if (ia == a.size()) {
        ib++;
        return;
      } else if (ib == b.size()) {
        ia++;
        return;
      } else {
        if (a[ia] < b[ib]) {
          ia++;
          return;
        } else {
          ib++;
          return;
        }
      }
    };

    auto get_location = [&]() {
      if (ia == a.size())
        return b[ib];
      else if (ib == b.size())
        return a[ia];
      return min(a[ia], b[ib]);
    };

    int mid_value = -1;

    int count = 0;
    while (ia < a.size() or ib < b.size()) {
      if (count == mid_location) {
        mid_value = get_location();
        break;
      }
      count++;
      move_indices();
    }

    if (get_next) {
      move_indices();
      int next_value = get_location();

      return ((double)(mid_value + next_value)) / 2;
    } else {
      return (double)(mid_value);
    }
  }
};
