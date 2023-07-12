#include <iostream>
#include <string>
using namespace std;

void asci_finder() {

  char c;
  cout << "enter character" << endl;
  cin >> c;
  cout << c - 0 << endl;
}

void string_comparision(string a, string b) {
  int i = 0, j = 0;
  int val = -1;
  while (i < a.size() and j < b.size()) {
    bool ang = false, bng = false;
    if (a[i] == 'n' and a[i + 1] == 'g')
      ang = true;
    if (b[j] == 'n' and b[j + 1] == 'g')
      bng = true;
    if (ang and bng) {
      i += 2;
      j += 2;
      continue;
    } else if (ang and not bng) {
      val = 1;
      break;
    } else if (not ang and bng) {
      val = 1;
      break;
    }
    if (a[i] > b[j]) {
      val = 1;
      break;
    } else if (a[i] < b[j]) {
      break;
    } else {
      i += 1;
      j += 1;
      continue;
    }
  }
  cout << val << endl;
  return;
}

int main() {
  asci_finder();
  string a, b;
  cout << "enter the stirngs" << endl;
  cin >> a >> b;
  string_comparision(a, b);
  return 0;
}
