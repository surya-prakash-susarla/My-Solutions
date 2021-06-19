#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  vector<long long int> a;
  for (int i = 0; i < n; i++) {
    long long int temp;
    cin >> temp;
    a.push_back(temp);
  }
  sort(a.begin(), a.end());
  vector<long long int>::iterator it;
  //	cout<<"the elements after sorting are "<<endl;
  //	for(it=a.begin();it!=a.end();it++)
  //		cout<<*it<<"\t";
  long long int smallest = -1;
  for (int i = 0; i < a.size() - 1; i++)
    if (smallest == -1 or abs(a[i + 1] - a[i]) < smallest)
      smallest = abs(a[i + 1] - a[i]);
  //	cout<<"the smallest value is ";
  cout << smallest << endl;
  return 0;
}
