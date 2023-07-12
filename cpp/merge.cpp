#include <iostream>
using namespace std;
void merge(int *a, int start, int end) {
  int mid = (start + end) / 2;
  if (mid <= 0)
    return;
  if (mid == 2)
    merge(0, mid);
  merge(mid, n);
}
int main() {
  int n;
  cout << "Enter the size of the array" << endl;
  int *a = new int[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  merge(a, 0, n);
}
