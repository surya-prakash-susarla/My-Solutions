#include <iostream>
#include <vector>
using namespace std;
vector<int> qs(vector<int> a) {
  if (a.size() <= 1)
    return a;
  int pivot = a[a.size() - 1];
  vector<int> left, right;
  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i] < pivot)
      left.push_back(a[i]);
    else if (a[i] > pivot) {
      right.push_back(a[i]);
    }
  }
  left = qs(left);
  right = qs(right);
  a.clear();
  a.insert(a.end(), left.begin(), left.end());
  a.push_back(pivot);
  a.insert(a.end(), right.begin(), right.end());
  return a;
}
int main() {
  cout << "enter the numbers ......... enter -1 to stop" << endl;
  int t = 1;
  cin >> t;
  vector<int> a;
  while (t != -1) {
    a.push_back(t);
    cin >> t;
  }
  cout << "calling the main sorting function" << endl;
  a = qs(a);
  cout << "starting display of elements" << endl;
  vector<int>::iterator it;
  for (it = a.begin(); it != a.end(); it++)
    cout << *it << "\t";
  cout << endl;
  return 0;
}
