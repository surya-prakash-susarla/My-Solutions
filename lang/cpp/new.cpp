#include <algorithm>
#include <cstdlib>
#include <iostream>
typedef long long int llint;
using namespace std;

// display function not useful in final
/*void printer ( vector<llint> a){
        vector<llint>::iterator it;
        for(it = a.begin() ; it!=a.end() ; it++)
                cout<<*it<<" ";
        cout<<endl;
}
*/
int main() {
  llint t;
  //	cout<<"enter the number of test cases"<<endl;
  cin >> t;
  while (t-- > 0) {
    llint n;
    //		cout<<"enter the number of items"<<endl;
    cin >> n;
    vector<llint> a, orig;
    //		cout<<"enter the elements"<<endl;
    for (llint i = 0; i < n; i++) {
      orig.push_back(i + 1);
      llint temp;
      cin >> temp;
      a.push_back(temp);
    }
    bool equal = false;
    llint b = 0;
    bool chaos = false, fucked = false;
    while (not equal) {
      for (llint i = 0; i < n; i++) {
        if (a[i] > orig[i]) {
          llint index = -1;
          bool found = false;
          for (llint j = 0; j < n and not found; j++) {
            if (orig[j] == a[i]) {
              index = j;
              found = true;
            }
          }
          orig.erase(orig.begin() + index);
          llint cub = abs(index - i);
          if (cub > 2)
            fucked = true;
          if (fucked) {
            equal = true;
            chaos = true;
            goto z;
          }

          b = b + cub;
          orig.insert(orig.begin() + i, a[i]);
        }
        equal = true;
        for (llint i = 0; i < n and equal; i++)
          if (a[i] != orig[i])
            equal = false;
        //				cout<<"the element being checked is
        //"<<a[i]<<endl<<"the current number of bribes are "<<b<<endl;
        //				cout<<"the order while changing is
        //"<<endl; 				printer(orig);
      }
    z:
      if (chaos)
        cout << "Too chaotic" << endl;
    }
    //		cout<<endl<<"the given order"<<endl;
    //		printer(a);
    //		cout<<"the final order"<<endl;
    //		printer(orig);
    if (not chaos)
      //		cout<<"the total number of bribes required are ";
      cout << b << endl;
  }
  //	cout<<"exiting the program"<<endl;
  return 0;
}
