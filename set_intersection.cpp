#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  set<int> temp;
  set<int> temper;
  temp.insert(10);
  temp.insert(20);
  temp.insert(30);
  temp.insert(40);

  temper.insert(20);
  temper.insert(40);
  temper.insert(60);

  set<int> final_values;
  set_intersection(temp.begin(), temp.end(), temper.begin(), temper.end(),
                   std::inserter(final_values, final_values.begin()));

  cout << "the values are " << endl;
  for (set<int>::iterator it = final_values.begin(); it != final_values.end();
       it++)
    cout << *it << endl;
  return 0;
}