#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  vector<int> values;
  set<int> set_values;

  for (int i = 0; i < 5; i++) {
    int temp;
    cin >> temp;
    values.push_back(temp);
  }

  for (int i = 0; i < 5; i++)
    set_values.insert(values[i]);

  cout << endl << "printing set values" << endl;
  ;

  for (set<int>::iterator it = set_values.begin(); it != set_values.end(); it++)
    cout << *it << endl;

  return 0;
}