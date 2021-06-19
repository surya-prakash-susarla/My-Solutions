#include <iostream>
#include <string>
using namespace std;
typedef long long int llint;

llint dot_finder(llint pos, string s, char prev, char &next) {
  //// cout<<"inside dot_finder"<<endl;
  //// cout<<s[pos]<<" "<<prev<<endl;
  if (next != 'Z' and s[pos] == next) {
    if (s[pos] == 'A')
      return 1;
    else
      return 2;
  } else if (next != 'Z' and s[pos] != next)
    return 0;
  for (llint i = pos; i < s.size(); i++) {
    if (s[i] == '.')
      continue;
    else if (s[i] == prev) {
      if (s[i] == 'A') {
        next = 'A';
        return 1;
      } else if (s[i] == 'B') {
        next = 'B';
        return 2;
      }
    } else {
      // cout<<"characters do not match"<<endl;
      return 0;
    }
  }
  return 0;
}

void village_counter(string s, llint &vila, llint &vilb) {
  char prev = 'Z';
  char next = 'Z';
  for (llint i = 0; i < s.size(); i++) {
    // cout<<"the values are "<<endl<<vila<<" "<<vilb<<" "<<s[i]<<"
    // "<<prev<<endl;
    if (s[i] == 'A') {
      prev = 'A';
      vila += 1;
      next = 'Z';
    } else if (s[i] == 'B') {
      prev = 'B';
      vilb += 1;
      next = 'Z';
    } else {
      llint result = dot_finder(i + 1, s, prev, next);
      // cout<<"result is "<<result<<endl;
      if (result == 1)
        vila += 1;
      else if (result == 2)
        vilb += 1;
    }
  }
  return;
}

int main(int argc, char const *argv[]) {
  llint t;
  //  // cout<<"enter the number of test cases"<<endl;
  cin >> t;
  while (t-- > 0) {
    string s;
    //    // cout<<"enter the string"<<endl;
    cin >> s;
    llint vila = 0, vilb = 0;
    village_counter(s, vila, vilb);
    cout << vila << " " << vilb;
    if (t > 0)
      cout << endl;
  }
  //  // cout<<"program terminated "<<endl;
  return 0;
}
