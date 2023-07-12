#include <iostream>
#include <vector>
using namespace std;
void dis(vector<int> v) {
  vector<int>::iterator f;
  for (f = v.begin(); f != v.end(); f++)
    cout << *f << "\t";
  cout << endl;
  return;
}
int main() {
  int vec_size, sub_size;
  cout << "Enter the size of the vector and the size of the sub-array" << endl;
  cin >> vec_size >> sub_size;
  vector<int>::iterator f;
  vector<int> a;
  cout << "Enter the elements of the vector" << endl;
  for (int i = 0; i < vec_size; i++) {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }
  int n = vec_size, k = sub_size;
  vector<int> temper;
  for (int i = 0; i < n; i++) {
    temper.clear();
    int pos = i;
    int count = 0;
    while (count < k - 1) {
      temper.push_back(a[pos++]);
      count++;
    }
    if (count == k - 1) {
      int t = pos;
      while (t < a.size()) {
        temper.push_back(a[t++]);
        dis(temper);
        temper.pop_back();
      }
    }
  }
}
