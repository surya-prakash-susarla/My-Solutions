
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> con_vec(string input) {
  vector<char> temp;
  for (int i = 0; i < input.size(); i++)
    temp.push_back(input[i]);
  return temp;
}

vector<int> largest_distances;

bool convert(vector<char> con, vector<char> target, int con_in, int tar_in,
             int moves) {
  if (tar_in == target.size()) {
    moves = moves + (con.size() - con_in);
    largest_distances.push_back(moves);
    return true;
  }
  if (con_in >= con.size() and tar_in < target.size())
    return false;
  if (con[con_in] == target[tar_in])
    return convert(con, target, con_in + 1, tar_in + 1, moves);
  // inserting new data
  vector<char> temp = con;
  temp.insert(temp.begin() + con_in, target[tar_in]);
  bool ins = convert(temp, target, con_in + 1, tar_in + 1, moves + 1);
  // replacing the data
  temp = con;
  temp[con_in] = target[tar_in];
  bool rep = convert(temp, target, con_in + 1, tar_in + 1, moves + 1);
  // deleting a value
  temp = con;
  temp.erase(temp.begin() + con_in);
  bool del = convert(temp, target, con_in, tar_in, moves + 1);
  return ins or rep or del;
}

int main() {
  string a, b;
  cin >> a;
  cin >> b;
  if (a.size() > b.size())
    cout << (int)convert(con_vec(a), con_vec(b), 0, 0, 0);
  else
    cout << (int)convert(con_vec(b), con_vec(a), 0, 0, 0);
  cout << " completed function calls " << endl;
  cout << "final answer : "
       << *min_element(largest_distances.begin(), largest_distances.end())
       << endl;
  cout << " TERMINATION" << endl;
  return 0;
}