#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int v, h;
    string s;
    cin >> v >> h;
    int bv = v, bh = h;
    cin >> s;
    char fh, fd;
    int nu = 0, nd = 0, nl = 0, nr = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'U')
        nu += 1;
      else if (s[i] == 'D')
        nd += 1;
      else if (s[i] == 'L')
        nl += 1;
      else
        nr += 1;
    }

    bool gone = false;
    bool ht = false, vt = false;
    if (nu > 0 && nd == 0) {
      v = v - nu;
      vt = true;
      if (v < 0)
        gone = true;
    } else if (nd > 0 && nu == 0) {
      v = v - nd;
      vt = true;
      if (v < 0)
        gone = true;
    }
    if (nr > 0 && nl == 0) {
      h = h - nr;
      ht = true;
      if (h < 0)
        gone = true;
    } else if (nl > 0 && nr == 0) {
      h = h - nl;
      ht = true;
      if (h < 0)
        gone = true;
    }
    if (!vt && !gone) {
      if (nu >= nd) {
        v = v - nu;
        if (v <= 0) {
          gone = true;
        }
        v = v + nd;
        if (v > 0)
          gone = true;
      } else {
        v = v - nd;
        if (v <= 0) {
          gone = true;
        }
        v = v + nu;
        if (v > bv)
          gone = true;
      }
    }
    if (!ht && !gone) {
      if (nr >= nl) {
        h = h - nr;
        if (h <= 0) {
          gone = true;
        }
        h = h + nl;
        if (h > bh)
          gone = true;
      } else {
        h = h - nl;
        if (h <= 0) {
          gone = true;
        }
        h = h + nr;
        if (h > bh)
          gone = true;
      }
    }

    // cout<<"Vertical = "<<v<<"  Horizontal = "<<h<<endl;

    if (gone)
      cout << "unsafe";
    else
      cout << "safe";

    if (t > 1)
      cout << endl;
  }
  return 0;
}
