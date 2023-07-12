#include <algorithm>
#include <iostream>
#include <vector>

#define null_double vector<vector<int>>()
#define null NULL
#define double_vector vector<vector<int>>

using namespace std;

double_vector subset_finder(vector<int> elements, int n) {
  if (n == 0)
    return null_double;
  double_vector final_values;
  for (int i = 0; i < elements.size(); i++) {
    vector<int> temp;
    temp.push_back(elements[i]);
    vector<int> changer = elements;
    changer.erase(find(changer.begin(), changer.end(), elements[i]));
    double_vector comb = subset_finder(changer, n - 1);
    if (comb.size() == 0)
      final_values.push_back(temp);
    for (int j = 0; j < comb.size(); j++) {
      vector<int> temper;
      temper.insert(temper.end(), temp.begin(), temp.end());
      temper.insert(temper.end(), comb[j].begin(), comb[j].end());
      final_values.push_back(temper);
    }
  }
  return final_values;
}

void double_printer(double_vector input) {
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[i].size(); j++)
      cout << input[i][j] << "\t";
    cout << endl;
  }
  return;
}

int main() {
  cout << "Enter 5 elements " << endl;
  vector<int> elements;
  for (int i = 0; i < 5; i++) {
    int temp;
    cin >> temp;
    elements.push_back(temp);
  }
  cout << " starting printing" << endl;
  for (int i = 0; i < elements.size(); i++)
    double_printer(subset_finder(elements, i));
  cout << " end of procedure" << endl;
  return 0;
}
