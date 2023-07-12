#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> a;
  for (int i = 0; i < 5; i++) {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }
  cout << "printing the elements" << endl;
  for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
    if (it - a.begin() != 3)
      cout << *it << endl;
    else
      cout << "caught" << endl;
  return 0;
}
