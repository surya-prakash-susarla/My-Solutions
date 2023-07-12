#include <iostream>
#include <vector>
using namespace std;
int s_size, n;
int *a;

void display(vector<int> a) {
  vector<int>::iterator f;
  for (f = a.begin(); f != a.end(); f++)
    cout << *f << "\t";
  cout << endl;
}

void sub_array_patterns(vector<int> d, int index = 0, int count = 0) {
  if (count < s_size) {
    count++;
    for (int i = index; i < n; i++) {
      vector<int> temp = d;
      temp.push_back(a[i]);
      // cout<<"Calling recursive"<<endl;
      sub_array_patterns(temp, i + 1, count);
      // cout<<"Received recursive"<<endl;
    }
  } else if (count == s_size) {
    for (int i = index; i < n; i++) {
      d.push_back(a[i]);
      display(d);
      d.pop_back();
    }
  }
}

int main() {
  cout << "Enter the size of the array" << endl;
  cin >> n;
  a = new int[n];
  cout << "Enter the elements of the array" << endl;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << "Enter the size of the sub array" << endl;
  cin >> s_size;
  s_size -= 1;
  vector<int> temp;
  sub_array_patterns(temp, 0, 0);
  return 0;
}
