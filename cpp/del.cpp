#include <algorithm>
#include <iostream>
#include <vector>
#define empty vector<int>(1, -1)
using namespace std;
int size1, size2;
vector<int> a, b;
void init(vector<vector<vector<int>>> &mem) {
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < b.size(); j++) {
      mem[i][j] = empty;
    }
}
void input(vector<int> &a, int size) {
  for (int i = 0; i < size; i++) {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }
  return;
}
vector<int> join(vector<int> a, vector<int> b) {
  vector<int> temp;
  for (int i = 0; i < a.size(); i++)
    temp.push_back(a[i]);
  for (int i = 0; i < b.size(); i++)
    temp.push_back(b[i]);
  return temp;
}
vector<int> find_values(int element, int b_start) {
  vector<int> temp;
  for (int i = b_start; i < b.size(); i++)
    if (b[i] == element)
      temp.push_back(i);
  return temp;
}
vector<int> sub_finder(int ina, int inb, vector<vector<vector<int>>> &mem,
                       vector<int> value) {
  if (ina >= (int)a.size() or inb >= (int)b.size())
    return value;
  if (ina < a.size() and inb < b.size() and mem[ina][inb] != empty) {
    return mem[ina][inb];
  }
  vector<int> skipped_value_ind = sub_finder(ina + 1, inb, mem, vector<int>());
  vector<int> skipped_result = join(value, skipped_value_ind);
  vector<int> final_result = skipped_value_ind;
  int max_length = skipped_value_ind.size();
  vector<int> indices = find_values(a[ina], inb);
  if (indices.size() > 0) {
    for (int i = 0; i < indices.size(); i++) {
      vector<int> result =
          sub_finder(ina + 1, indices[i] + 1, mem, vector<int>());
      vector<int> temp_result;
      temp_result.push_back(a[ina]);
      temp_result = join(temp_result, result);
      if ((int)temp_result.size() > max_length) {
        max_length = (int)temp_result.size();
        final_result = temp_result;
      }
    }
  }
  mem[ina][inb] = final_result;
  return join(value, final_result);
}
int main() {
  cin >> size1 >> size2;
  input(a, size1);
  input(b, size2);
  vector<vector<vector<int>>> mem(size1, vector<vector<int>>(size2));
  init(mem);
  vector<int> final_result = sub_finder(0, 0, mem, vector<int>());
  for (int i = 0; i < final_result.size(); i++)
    cout << final_result[i] << endl;
  return 0;
}