#include <iostream>
using namespace std;
int *a, size;
void printer(int *a, int start, int stop) {
  for (int i = 0; i < start; i++)
    cout << a[i] << " ";
  for (int i = start; i <= stop; i++)
    cout << a[i] << " ";
  for (int i = stop + 1; i < size; i++)
    cout << a[i] << " ";
  cout << endl;
  return;
}
void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}
int find(int *a, int pivot, int start, int stop) {
  for (int i = start; i <= stop; i++)
    if (a[i] > pivot)
      return i;
  return -1;
}
bool sorted(int *a, int start, int stop) {
  for (int i = start; i < stop; i++)
    if (a[i] > a[i + 1])
      return false;
  return true;
}
void qs(int start, int stop) {
  if (sorted(a, start, stop) || stop - start == 1 || start < 0 || stop < 0 ||
      start >= size || stop >= size || start == stop)
    return;
  int pivot = a[stop];
  int high = -1;
  for (int i = start; i < stop; i++) {
    if (a[i] > pivot)
      if (high == -1 || high > i)
        high = i;
    if (a[i] < pivot and high != -1) {
      swap(a[i], a[high]);
      high = find(a, pivot, start, stop);
    }
  }
  if (high != -1)
    swap(a[high], a[stop]);
  if (high == -1)
    high = stop;
  // printer(a,start,stop);
  if (sorted(a, start, stop))
    return;
  qs(start, high - 1);
  qs(high + 1, stop);
}
int main() {
  cin >> size;
  a = new int[size];
  for (int i = 0; i < size; i++)
    cin >> a[i];
  qs(0, size - 1);
  for (int i = 0; i < size; i++)
    cout << a[i] << "\t";
  int median_pos = size / 2;
  cout << a[median_pos] << endl;
  return 0;
}
