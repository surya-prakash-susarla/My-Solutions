#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int **data;
bool matcher(string a, string b) {
  //	cout<<"in function for \n "<<a<<"\t"<<b<<endl;
  if (data[a.size()][b.size()] != -1)
    if (data[a.size()][b.size()] == 1)
      return true;
    else
      return false;
  if (a.size() == 0 and b.size() != 0)
    return data[a.size()][b.size()] = false;
  if (b.size() == 0)
    return data[a.size()][b.size()] = true;
  int pos1 = a.size() - 1;
  int pos2 = b.size() - 1;
  //	cout<<"checking for "<<a[pos1]<<" "<<b[pos2]<<endl;
  if (b[pos2] == a[pos1] or b[pos2] == toupper(a[pos1]))
    return data[a.size() - 1][b.size()] =
               matcher(a.substr(0, a.size() - 1), b) or
               (data[a.size() - 1][b.size() - 1] = matcher(
                    a.substr(0, a.size() - 1), b.substr(0, b.size() - 1)));
  else if (islower(a[pos1]))
    return data[a.size() - 1][b.size()] = matcher(a.substr(0, a.size() - 1), b);
  else
    return data[a.size()][b.size()] = false;
}
int main() {
  int t;
  //	cout<<"test cases"<<endl;
  cin >> t;
  while (t-- > 0) {
    string a, b;
    //		cout<<"enter the strings"<<endl;
    cin >> a >> b;
    data = new int *[a.size() + 1];
    for (int i = 0; i < a.size() + 1; i++) {
      data[i] = new int[b.size() + 1];
      for (int j = 0; j < b.size() + 1; j++)
        data[i][j] = -1;
    }

    //		cout<<"before function call"<<endl;
    if (matcher(a, b))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    free(data);
  }
  return 0;
}
