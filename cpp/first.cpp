#include <iostream>
#include <string>
#include <vector>
using namespace std;
class variable {
public:
  char c;
  vector<string> productions;
  string first;
};
vector<variable> variables;
string substring(string a, int index1, int final_index) {
  string temp = "";
  for (int i = index1; i < final_index; i++)
    temp = temp + a[i];
  return temp;
}
void first(string input, string &final_value) {
  if (input.size() == 0)
    final_value += '@';
  if (input[0] == '@')
    first(substring(input, 1, input.size()), final_value);
  if ((input[0] >= 'a' and input[0] <= 'z') or input[0] == '+' or
      input[0] == '-' or input[0] == '*') {
    final_value += input[0];
    return;
  }
  variable temp;
  for (int i = 0; i < variables.size(); i++)
    if (variables[i].c == input[0]) {
      temp = variables[i];
      break;
    }
  for (int i = 0; i < temp.productions.size(); i++)
    first(temp.productions[i] + substring(input, 1, input.size()), final_value);
  return;
}
int main() {
  int n;
  cout << "Enter the number of productions" << endl;
  cin >> n;
  while (n-- > 0) {
    string temp;
    cin >> temp;
    variable temp_variable;
    temp_variable.c = temp[0];
    temp = substring(temp, 3, temp.size());
    int index = 0;
    string temper = "";
    while (index < temp.size()) {
      if (temp[index] != '/')
        temper = temper + temp[index];
      else {
        temp_variable.productions.push_back(temper);
        temper = "";
      }
      index++;
    }
    temp_variable.productions.push_back(temper);
    variables.push_back(temp_variable);
  }
  cout << "the first values are " << endl;
  for (int i = 0; i < variables.size(); i++)
    for (int j = 0; j < variables[i].productions.size(); j++)
      first(variables[i].productions[j], variables[i].first);
  for (int i = 0; i < variables.size(); i++)
    cout << variables[i].first << endl;
  return 0;
}
