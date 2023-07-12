#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;
llint first_length, second_length;
vector<llint> first, count_first, second, count_second;

int find_index(int number, vector<llint> lister) {
  for (llint i = 0; i < lister.size(); i++)
    if (lister[i] == number)
      return i;
  return -1;
}

void main_calculator() {
  for (llint i = 0; i < first.size(); i++) {
    llint index = find_index(first[i], second);
    count_second[index] = count_second[index] - count_first[i];
  }
  vector<llint> final_temp;
  for (llint i = 0; i < second.size(); i++)
    if (count_second[i] != 0)
      final_temp.push_back(second[i]);
  sort(final_temp.begin(), final_temp.end());
  for (llint i = 0; i < final_temp.size(); i++)
    cout << final_temp[i] << " ";
  cout << endl;
  return;
}

int main(int argc, char const *argv[]) {
  cout << "enter the value of m" << endl;
  cin >> first_length;
  cout << "enter the values" << endl;
  for (llint i = 0; i < first_length; i++) {
    llint temp;
    cin >> temp;
    llint index = find_index(temp, first);
    if (index != -1)
      count_first[index] += 1;
    else {
      first.push_back(temp);
      count_first.push_back(0);
    }
  }
  cout << "enter the value of n" << endl;
  cin >> second_length;
  cout << "enter the values" << endl;
  for (llint i = 0; i < second_length; i++) {
    llint temp;
    cin >> temp;
    llint index = find_index(temp, second);
    if (index != -1)
      count_second[index] += 1;
    else {
      second.push_back(temp);
      count_second.push_back(0);
    }
  }
  cout << "the value of the first array are " << endl;
  for (llint i = 0; i < first.size(); i++)
    cout << first[i] << " " << count_first[i] << endl;
  cout << "the value of the second array are " << endl;
  for (llint i = 0; i < second.size(); i++)
    cout << second[i] << " " << count_second[i] << endl;
  main_calculator();
  return 0;
}
