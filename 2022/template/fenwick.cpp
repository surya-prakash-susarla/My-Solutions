#include <bits/stdc++.h>

using namespace std;

// Fenwick tree/ Binary Indexed Tree

class __fwt {
 public:
  explicit __fwt(const vector<int>& values) {
    this->values = vector<int>(values.size() + 1);
    original = values;
    cout << "--------- creating fwt" << endl;
    for (int i = 0; i < values.size(); i++)
      init_node(i + 1, values[i]);
    cout << "--------- fwt created" << endl;

    print_tree();
  }

  void init_node(int index, int val) {
    while (index < values.size()) {
      values[index] += val;
      index = get_next(index);
    }
  }

  void print_tree() {
    cout << "------- printing fwt" << endl;
    for (int i : values)
      cout << i << " ";
    cout << endl;
    cout << "------- printing fwt done" << endl;
  }

  int get_next(int index) { return index + (index & -index); }

  int get_parent(int index) { return index - (index & -index); }

  void update_node(int index, int val) {
    cout << "------- updating nodes" << endl;
    cout << "current op : " << index << " " << val << endl;
    int update = val - original[index];
    original[index] = val;
    index++;
    while (index < values.size()) {
      cout << "updating index : " << index << " from : " << values[index]
           << " to : " << values[index] + update << endl;
      values[index] += update;
      index = get_next(index);
    }

    cout << "-------- update complete" << endl;
    print_tree();

    return;
  }

  int get_sum(int index) {
    index++;
    int answer = 0;
    while (index > 0) {
      answer += values[index];
      index = get_parent(index);
    }
    return answer;
  }

  int get_range_sum(int left, int right) {
    return get_sum(right) - get_sum(left - 1);
  }

 private:
  vector<int> original;
  vector<int> values;
};

int main() {
  // Case #1:
  {
    // vector<int> values = {3, 4, 5, 6, 7};

    // __fwt temp(values);
    // temp.update_node(1, 9);
    // temp.update_node(3, 13);

    // cout << "sum to index 4 : " << temp.get_sum(4) << endl;
    // cout << "sum to index 2 : " << temp.get_sum(2) << endl;

    // cout << "sum to range 1 - 3 : " << temp.get_range_sum(1, 3) << endl;
    // cout << "sum to range 0 - 4 : " << temp.get_range_sum(0, 4) << endl;
    // cout << "sum to range 2 - 3 : " << temp.get_range_sum(2, 3) << endl;
  }
  // Case #2:
  {
    vector<int> values = {7, 2, 7, 2, 0};

    __fwt temp(values);
    temp.update_node(4, 6);
    temp.update_node(0, 2);
    temp.update_node(0, 9);
    cout << " <<<<<<<<<<<<<<<< sum to range 4 - 4 : " << temp.get_range_sum(4, 4) << endl;
    temp.update_node(3, 8);
    cout << " <<<<<<<<<<<<<<<< sum to range 0 - 4 : " << temp.get_range_sum(0, 4) << endl;
    temp.update_node(4, 1);
    cout << " <<<<<<<<<<<<<<<< sum to range 0 - 3 : " << temp.get_range_sum(0, 3) << endl;
    cout << " <<<<<<<<<<<<<<<< sum to range 0 - 4 : " << temp.get_range_sum(0, 4) << endl;
    temp.update_node(0, 4);
  }

  return 0;
}