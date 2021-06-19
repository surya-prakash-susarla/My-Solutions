#include <iostream>
#include <vector>
using namespace std;
class temp {
public:
  int a, b;
  void print() { cout << a << " " << b << endl; }
};
vector<temp> a;
int main() {
  for (int i = 0; i < 5; i++) {
    int g, h;
    cin >> g >> h;
    temp t;
    t.a = g;
    t.b = h;
    a.push_back(t);
  }
  cout << "the entered elements are " << endl;
  for (int i = 0; i < a.size(); i++)
    a[i].print();
  cout << "terminating" << endl;
  return 0;
}
