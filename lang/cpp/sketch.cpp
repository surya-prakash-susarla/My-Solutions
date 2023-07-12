#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> store;

string find_common(string a, string b, int ina, int inb, string temp,
                   vector<vector<string>> &stored) {
  if (ina == a.size() or inb == b.size()) {
    // cout<<"limit reached "<<endl;
    // cout<<"value of temp is "<<temp <<endl;
    return temp;
  }
  string matched = "";
  if (a[ina] == b[inb])
    matched = find_common(a, b, ina + 1, inb + 1, temp + a[ina], stored);
  string skip_a = find_common(a, b, ina + 1, inb, "", stored);
  string skip_b = find_common(a, b, ina, inb + 1, "", stored);

  // cout<<"the value of matched is "<<matched<<endl;
  // cout<<"the value of skip_a is "<<skip_a <<endl;
  // cout<<"the value of skip_b is "<<skip_b<<endl;

  if (matched.size() > skip_a.size() and matched.size() > skip_b.size())
    stored[ina][inb] = matched;
  else if (skip_a.size() > matched.size() and skip_a.size() > skip_b.size())
    stored[ina][inb] = skip_a;
  else
    stored[ina][inb] = skip_b;
  return stored[ina][inb];
}

int main() {
  cout << "Enter two strings" << endl;
  string a, b;
  cin >> a >> b;
  vector<vector<string>> visited(a.size(), vector<string>(b.size(), ""));
  string answer = find_common(a, b, 0, 0, "", visited);
  cout << "answer is " << answer << endl;
  cout << "the matrix is " << endl;
  for (int i = 0; i < visited.size(); i++) {
    for (int j = 0; j < visited[i].size(); j++)
      cout << visited[i][j] << "\t";
    cout << endl;
  }
  cout << "End of items" << endl;
  return 0;
}