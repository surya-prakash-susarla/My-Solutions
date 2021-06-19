#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int size1, size2;
vector<int> a, b;

vector<int> find(int element, int inb) {
  vector<int> values;
  for (int i = inb; i < b.size(); i++) {
    if (b[i] == element)
      values.push_back(i);
  }
  return values;
}

void printer(vector<int> input) {
  cout << "PRINTER" << endl;
  for (int i = 0; i < input.size(); i++)
    cout << input[i] << endl;
  return;
}

vector<int> find_largest(int ina, int inb, vector<int> present) {
  cout << "INA : " << ina << " INB:" << inb << endl;
  printer(present);

  if (ina >= a.size() or inb >= b.size()) {
    cout << "TERMINAL" << endl;
    return present;
  }
  // call by skipping the current element
  vector<int> skip = find_largest(ina + 1, inb, present);
  cout << "INA : " << ina << " INB:" << inb << endl;
  cout << "SKIP" << endl;
  printer(skip);
  vector<int> final_values;
  int max_length = -1;

  if ((int)skip.size() > max_length) {
    max_length = skip.size();
    final_values = skip;
  }

  // call to find element at ina starting from position inb
  vector<int> indices = find(a[ina], inb);
  cout << "INDICES:" << endl;
  printer(indices);
  cout << "-----" << endl;
  if (indices.size() > 0)
    present.push_back(a[ina]);
  for (int i = 0; i < indices.size(); i++) {
    vector<int> temp_result = find_largest(ina + 1, indices[i] + 1, present);
    cout << "MAX LENGTH : " << max_length
         << "\tTEMP_RESULT:" << temp_result.size() << endl;
    printer(temp_result);
    cout << "RESULT BOOLEAN IS : "
         << (bool)((int)temp_result.size() > max_length) << endl;
    if ((int)temp_result.size() > max_length) {
      max_length = temp_result.size();
      final_values = temp_result;
      cout << "UPDATED FINAL VALUES" << endl;
      printer(final_values);
    }
  }
  // returning the max result of all the available subsequences
  cout << "FINAL VALUES:" << endl;
  printer(final_values);
  return final_values;
}

int main() {
  cout << "Enter the size 1 " << endl;
  cin >> size1;
  cout << "Enter the size 2 " << endl;
  cin >> size2;
  cout << "Enter the contents of the vector 1 " << endl;
  for (int i = 0; i < size1; i++) {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }
  cout << "Enter the contents of the vector 2" << endl;
  for (int i = 0; i < size2; i++) {
    int temp;
    cin >> temp;
    b.push_back(temp);
  }
  cout << "Starting the main function for checking the longest subsequence in "
          "the given vectors"
       << endl;
  // call to the imp function
  vector<int> longest = find_largest(0, 0, vector<int>());
  cout << "The result is " << endl;
  for (int i = 0; i < longest.size(); i++)
    cout << longest[i] << endl;
  cout << "Terminating the program" << endl;
  return 0;
}