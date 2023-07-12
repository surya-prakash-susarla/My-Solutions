#include <iostream>
#include <vector>
using namespace std;
#define nuller vector<int>()

vector<int> a, b;

void printer(vector<int> a) {
  // cout << "in printer function" <<endl;
  for (int i = 0; i < a.size(); i++)
    cout << a[i] << " ";
  cout << endl;
  // cout<<"completed printing "<<endl;
  return;
}

vector<int> join(int a, vector<int> ender) {
  // cout << "joining "<<a << " and "<<endl;
  // printer(ender);
  vector<int> temp;
  temp.push_back(a);
  temp.insert(temp.end(), ender.begin(), ender.end());
  // cout<<"returning the following vector"<<endl;
  // printer(temp);
  return temp;
}

vector<int> ss(int ina, int inb, vector<vector<vector<int>>> &data,
               vector<vector<bool>> &visited) {
  // cout << "in function with indices "<<ina<<" and "<<inb<<endl;
  if (ina == a.size() or inb == b.size()) {
    // cout << "reached ending of the vector , therefore returning "<<endl;
    return nuller;
  }
  if (visited[ina][inb]) {
    // cout <<"returning from previous result"<<endl;
    return data[ina][inb];
  }
  if (a[ina] == b[inb]) {
    // cout << " incrementing since both values match i.e.,
    // "<<ina<<"\t"<<inb<<endl;
    data[ina][inb] = join(a[ina], ss(ina + 1, inb + 1, data, visited));
    visited[ina][inb] = true;
    return data[ina][inb];
  } else {
    // cout << "calculating values since chars do not match "<<endl;
    vector<int> t1 = ss(ina + 1, inb, data, visited);
    vector<int> t2 = ss(ina, inb + 1, data, visited);
    if (t1.size() > t2.size())
      data[ina][inb] = t1;
    else
      data[ina][inb] = t2;
    visited[ina][inb] = true;
    // cout << "value of "<<ina<<"\t"<<inb<<endl;
    // printer(data[ina][inb]);
    return data[ina][inb];
  }
  // cout<< "program should not come here and it never will :-)"<<endl;
  return nuller;
}

int main(int argc, char const *argv[]) {
  int asize, bsize;
  // cout << "enter asize and bsize "<<endl;
  cin >> asize >> bsize;
  // cout<<"enter contents of a "<<endl;
  for (int i = 0; i < asize; i++) {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }
  // cout<<"enter contents of b "<<endl;
  for (int j = 0; j < bsize; j++) {
    int temp;
    cin >> temp;
    b.push_back(temp);
  }
  // cout << " creating tables for data and visited "<<endl;
  vector<vector<vector<int>>> data(a.size(), vector<vector<int>>(b.size()));
  vector<vector<bool>> visited(a.size(), vector<bool>(b.size()));
  // cout<<" initializing tables for data and visited arrays "<<endl;
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < b.size(); j++) {
      data[i][j] = vector<int>();
      visited[i][j] = false;
    }
  // cout << "completed initializing , starting the function call "<<endl;
  printer(ss(0, 0, data, visited));
  // cout<<"\n\n\nprogram terminating "<<endl;
  return 0;
}
