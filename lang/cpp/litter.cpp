#include <iostream>
#include <vector>
using namespace std;

vector<int> join(int a, vector<int> ender) {
  vector<int> temp;
  temp.push_back(a);
  temp.insert(temp.end(), ender.begin(), ender.end());
  return temp;
}

void printer(vector<int> a) {
  for (int i = 0; i < a.size(); i++)
    cout << a[i] << endl;
  return;
}

void join_tester() {
  vector<int> temp;
  for (int i = 0; i < 5; i++) {
    int a;
    cin >> a;
    temp.push_back(a);
  }
  cout << "original numbers" << endl;
  printer(temp);
  temp = join(6, temp);
  cout << "numbers after joining" << endl;
  printer(temp);
}

void empty_printer() {
  cout << "calling printer on empty vector " << endl;
  printer(vector<int>());
  printer(join(6, vector<int>()));
}

int main(int argc, char const *argv[]) {
  join_tester();
  empty_printer();
  return 0;
}
