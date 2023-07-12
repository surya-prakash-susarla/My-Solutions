#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class variable {
public:
  char value;
  vector<string> productions;
};
// Declarations
vector<variable> variables;
string final_answer;
int current_location = 0;

int match(char c) {
  cout << " checking for match between answer = "
       << final_answer[current_location] << "\t" << c << endl;
  if (current_location == final_answer.size()) {
    cout << "returning -1 " << endl;
    return -1;
  }
  if (final_answer[current_location] == c)
    return 1;
  return 0;
}

bool non_terminal_checker(char symbol) {
  cout << "Currently checking in the symbol " << symbol << endl;
  vector<string> current_productions;
  for (int i = 0; i < variables.size(); i++)
    if (variables[i].value == symbol) {
      current_productions = variables[i].productions;
      break;
    }
  cout << "The productions are " << endl;
  for (int i = 0; i < current_productions.size(); i++)
    cout << current_productions[i] << endl;
  cout << "--------------------------------------------------------------------"
          "-----"
       << endl;
  int init = current_location;
  // checking for productions from given symbol
  for (int j = 0; j < current_productions.size(); j++) {
    bool production_works = true;
    cout << endl
         << "checking for answer using production " << current_productions[j]
         << endl;
    for (int i = 0; i < current_productions[j].size(); i++) {
      if (isupper(current_productions[j][i])) {
        bool answer = non_terminal_checker(current_productions[j][i]);
        if (not answer) {
          cout << " could not find answer from variable "
               << current_productions[j][i] << endl;
          production_works = false;
          break;
        }
      }
      // since the character is not a variable it has to be a terminal
      else {
        if (match(current_productions[j][i]) == 1)
          current_location++;
        else if (match(current_productions[j][i]) == -1) {
          if (i < current_productions[j].size())
            return false;
          else
            return true;
        } else {
          production_works = false;
          current_location = init;
          break;
        }
      }
    } // inside each production
    if (production_works)
      return true; // the current production fit in the final answer
  }                // loop over all the productions
  return false;    // since no productions matched
} // end of function

int main() {
  cout << "Enter the number of productions " << endl;
  int n;
  cin >> n;
  cout << "Enter the productions " << endl;
  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    char symbol = input[0];
    string temp = "";
    vector<string> temp_prods;
    int temp_index = 3;
    while (temp_index < input.size()) {
      if (input[temp_index] != '/')
        temp = temp + input[temp_index];
      else {
        temp_prods.push_back(temp);
        temp = "";
      }
      temp_index++;
    }
    temp_prods.push_back(temp);
    variable temp_variable;
    temp_variable.value = symbol;
    temp_variable.productions = temp_prods;
    variables.push_back(temp_variable);
  } // End of input
  cout << "Enter the string to be checked" << endl;
  cin >> final_answer;
  char start_symbol;
  cout << "Enter the start symbol" << endl;
  cin >> start_symbol;
  cout << "Starting RDP procedure" << endl;
  if (non_terminal_checker(start_symbol))
    cout << "YES --- The given string can be obtained using RDP" << endl;
  else
    cout << "NO --- The given string cannot be obtained using RDP" << endl;
  cout << endl << "End of the program" << endl;
  return 0;
}
