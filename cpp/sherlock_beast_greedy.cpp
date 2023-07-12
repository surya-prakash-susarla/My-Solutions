#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long int llint;

string find_answer(llint n) {
  vector<llint> number_of_threes, number_of_fives;
  for (llint i = 0; i <= n; i += 5)
    number_of_threes.push_back(i);
  for (llint i = 0; i <= n; i += 3)
    number_of_fives.push_back(i);

  // cout<<"the values of number_of_fives is "<<endl;
  // for(llint i=0;i<number_of_fives.size();i++)
  // cout<<number_of_fives[i]<<endl;
  // cout<<"\nthe values of number_of_threes is "<<endl;
  // for(llint i=0;i<number_of_threes.size();i++)
  // cout<<number_of_threes[i]<<endl;
  // cout<<endl;

  llint final_fives = -1, final_threes = -1;
  bool found = false;
  for (llint i = number_of_fives.size() - 1; i >= 0 and not found; i--)
    for (llint j = number_of_threes.size() - 1; j >= 0 and not found; j--)
      if (not found and number_of_fives[i] + number_of_threes[j] == n) {
        // cout<<"currently checking
        // "<<number_of_fives[i]<<"\t"<<number_of_threes[j]<<endl;
        final_fives = number_of_fives[i];
        final_threes = number_of_threes[j];
        found = true;
      }

  // cout<<"the value of final_fives is "<<final_fives<<"\nthe value of
  // final_threes is "<<final_threes<<endl;

  if (final_fives == -1 and final_threes == -1)
    return "-1";
  string final_answer;
  for (llint i = 0; i < final_fives; i++)
    final_answer += "5";
  for (llint i = 0; i < final_threes; i++)
    final_answer += "3";
  return final_answer;
}

int main(int argc, char const *argv[]) {
  llint t;
  // cout<<"enter the number of test cases"<<endl;
  cin >> t;

  while (t-- > 0) {
    llint n;
    // cout<<"enter the value of n"<<endl;
    cin >> n;
    string answer = find_answer(n);
    if (answer != "-1")
      cout << answer;
    else
      cout << "-1";
    if (t > 0)
      cout << endl;
  }
  return 0;
}
