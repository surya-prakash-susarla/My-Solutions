#include <iostream>

using namespace std;

int power(int base, int power_) { return base <<= (power_ - 1); }

int main() {
  int l, r;
  cin >> l >> r;
  int d = l ^ r;
  // cout<<d;
  int pos = 0;
  while (d != 0) {
    pos++;
    d >>= 1;
  }
  // cout<<"\nthe msb is at "<<pos<<endl;
  int sum = 0;
  pos -= 1;
  while (pos >= 0) {
    sum = sum + power(2, pos--);
    //  cout<<"the current sum is "<<sum<<endl;
  }
  sum += 1;
  cout << sum;
  return 0;
}
