#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
long long int capx, capy, max_limx, max_limy, min_limx, min_limy;

bool mid(long long int a, long long int b, long long int c, long long int d) {
  // cout<<a<<" "<<b<<"\t"<<c<<" "<<d<<endl;
  if ((a + c) % 2 != 0 or (b + d) % 2 != 0) {
    //	cout<<"the remainder is "<<(b+d)%2<<endl;
    return false;
  }
  // cout<<"the conditions are checked for integers"<<endl;
  if ((a + c) / 2 == capx and (b + d) / 2 == capy)
    return true;
  return false;
}

int main() {
  // cout<<"for based looping rather than while"<<endl;
  // cout<<"enter the minimum, maximum and capital ordinates"<<endl;
  cin >> min_limx >> min_limy >> max_limx >> max_limy >> capx >> capy;
  long long int citx, city, ditx, dity;
  long long int brid = 0;
  for (citx = capx, ditx = capx; citx >= min_limx and ditx <= max_limx;
       citx--, ditx++) {
    // city=max_limy;
    // dity=min_limy;
    long long int temp;
    max_limy - capy > capy - min_limy ? temp = capy - min_limy
                                      : temp = max_limy - capy;
    // cout<<temp<<endl;
    dity = capy - temp;
    city = capy + temp;
    // cout<<"city = "<<city<<" dity = "<<dity<<endl;
    // cout<<citx<<" "<<city<<"\t"<<ditx<<" "<<dity<<endl;
    for (city = capy + temp, dity = capy - temp;
         city >= min_limy and dity <= max_limy; city--, dity++) {
      if (mid(citx, city, ditx, dity)) {
        //		cout<<citx<<" "<<city<<"\t"<<ditx<<" "<<dity<<endl;
        brid++;
      }
    }
    if (citx == ditx) {
      brid -= 1;
      brid /= 2;
    }
  }
  cout << brid << endl;
  return 0;
}
