#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;
int main() {
  llint t;
  // cout<<"enter the number of test cases"<<endl;
  cin >> t;
  while (t-- > 0) {
    llint no;
    //	cout<<"enter the number of days"<<endl;
    cin >> no;
    //	cout<<"enter the prices of stocks"<<endl;
    vector<llint> st;
    for (llint i = 0; i < no; i++) {
      llint temp;
      cin >> temp;
      st.push_back(temp);
    }
    llint profit = 0, price = 0, num = 0;
    vector<llint>::iterator it;
    it = st.begin();
    while (it != st.end()) {
      vector<llint>::iterator temp;
      for (temp = it; temp != max_element(temp, st.end()); temp++) {
        price += *temp;
        num++;
      }
      profit += ((*temp) * num) - price;
      num = 0;
      price = 0;
      it = temp + 1;
    }
    cout << profit << endl;
  }
  return 0;
}
