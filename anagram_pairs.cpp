#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int back_finder(string b, char c, int limit) {
  for (int i = b.size() - 1; i > limit; i--)
    if (b[i] == c)
      return i;
  return -1;
}

string subst(string a, int start, int end) {
  string temp;
  for (int i = start + 1; i < end; i++)
    temp += a[i];
  return temp;
}

int anagram_checker(string a, char prev_char) {
  int i = 0, sum = 0;
  // cout<< "in anagram_checker with string = "<<a<<endl;
  while (i < a.size()) {
    // cout<<"checking for character "<<a[i]<<" in string "<<a<<" with sum =
    // "<<sum<<endl;
    int end_index = back_finder(a, a[i], i);
    // cout<<"index found for "<<a[i]<<" at "<<end_index<<endl;
    if (end_index > -1) {
      // cout<<"sending sub call for string between " <<i<<" and "<<end_index<<"
      // i.e., "<<subst ( a,i,end_index)<<endl;
      sum += anagram_checker(subst(a, i, end_index), a[i]) + 1;
      if (end_index - i > 1)
        sum += 1;
    }
    if (prev_char != '@' and a[i] == prev_char) {
      // cout << "adding +1 since char matches "<<prev_char<<" the current sum
      // is "<<sum<<endl;
      sum += 1;
    }
    i++;
  }
  // cout<<"returning from string "<<a<<" with value = "<<sum<<endl;
  return sum;
}

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t-- > 0) {
    string a;
    // cout<<"enter any string"<<endl;
    cin >> a;
    // cout<<"starting the function call\n\n\n"<<endl;
    cout << anagram_checker(a, '@');
    if (t > 0)
      cout << endl;
  }
  // cout<<"end of program "<<endl;
  return 0;
}
