#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> lexicalOrder(int n) {
  vector<string> values;
  for (int i = 1; i <= n; i++)
    values.push_back(to_string(i));
  sort(values.begin(), values.end());
  vector<int> temp;
  for (int i = 0; i < values.size(); i++)
    temp.push_back(stoi(values[i]));
  return temp;
}

void printer(vector<int> values) {
  cout << "printing" << endl;
  for (int i = 0; i < values.size(); i++)
    cout << values[i] << endl;
  return;
}

int main() {
  int n;
  cin >> n;
  printer(lexicalOrder(n));
  return 0;
}