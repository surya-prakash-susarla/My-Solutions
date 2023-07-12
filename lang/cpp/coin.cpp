#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;
/*
void printer(vector<llint> coins){
        vector<llint>::iterator it;
        for(it=coins.begin();it!=coins.end();it++)
                cout<<*it<<" ";
        cout<<endl;
}
*/
llint **vals_stored;

llint coin(vector<llint> coins, llint numc, llint val) {
  //	cout<<"the current value being searched "<<val<<endl;
  //	cout<<"the coins are "<<endl;
  //	printer(coins);
  if (val < 0)
    return 0;
  if (val == 0)
    return 1;
  if (numc == 0)
    return 0;
  //	cout<<"numc and val are "<<numc<<" "<<val<<endl;
  //	cout<<vals_stored[numc][val];
  if (vals_stored[numc][val] != -1)
    return vals_stored[numc][val];
  llint temp = coin(coins, numc, val - coins[numc - 1]);
  llint temper = 0;
  if (numc > 1)
    temper = coin(coins, numc - 1, val);
  //	cout<<"the number of ways to make "<<val<<" are "<<temp+temper<<endl;
  vals_stored[numc][val] = temp + temper;
  return temp + temper;
}

int main() {
  //	cout<<"enter the number of coins"<<endl;
  llint numc, value;
  cin >> value >> numc;
  //	cout<<"enter the coin denominations"<<endl;
  vector<llint> coins;
  for (llint i = 0; i < numc; i++) {
    llint temp;
    cin >> temp;
    coins.push_back(temp);
  }
  //	cout<<"enter the value to be found"<<endl;
  llint lowest = *min_element(coins.begin(), coins.end());
  vals_stored = new llint *[1000];
  llint siz = 300;
  for (llint i = 0; i < 1000; i++) {
    vals_stored[i] = new llint[siz];
    for (llint j = 0; j < siz; j++)
      vals_stored[i][j] = -1;
  }
  //	cout<<"before the tester comment"<<endl;
  //	cout<<"JUST ANOTHER TESTER COMMENT ----------
  //"<<vals_stored[numc-1][value-1]<<endl; 	cout<<"the number of ways this can be
  //acheived is "<<coin(coins,numc,value)<<endl;
  cout << coin(coins, numc, value) << endl;
  return 0;
}
