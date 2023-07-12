#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int llint;

llint **dis_set;

llint find(llint ed) {
  if (dis_set[ed][1] == -1)
    return dis_set[ed][0];
  else
    return find(dis_set[ed][1]);
}

void uni(llint node, llint parent) {
  llint np = find(node);
  llint pp = find(parent);
  dis_set[np][1] = pp;
  return;
}

llint find_min_edge(llint **edg, llint ne) {
  llint min = -1, minind = -1;
  for (llint i = 0; i < ne; i++) {
    if (edg[i][2] != -1) {
      if ((min != -1 and edg[i][2] < min) or min == -1) {
        min = edg[i][2];
        minind = i;
      }
    }
  }
  return minind;
}

llint use_edges(llint **edg, llint ne) {
  llint sum = 0;
  for (llint i = 0; i < ne; i++) {
    llint index = find_min_edge(edg, ne);
    if (index == -1)
      return sum;
    if (find(edg[index][0]) == find(edg[index][1])) {
      edg[index][2] = -1;
    } else {
      // // cout<<"the edge between "<<edg[index][0]<<" and "<<edg[index][1]<<"
      // is included"<<endl;
      // // cout<<"values are "<<find(edg[index][0])<<" and
      // "<<find(edg[index][1])<<endl;
      uni(edg[index][0], edg[index][1]);
      sum += edg[index][2];
      edg[index][2] = -1;
    }
  }
  return sum;
}

int main() {
  llint num;
  // // cout<<"enter the number of nodes"<<endl;
  cin >> num;
  dis_set = new llint *[num];
  for (llint i = 0; i < num; i++) {
    dis_set[i] = new llint[2];
    dis_set[i][0] = i;
    dis_set[i][1] = -1;
  }
  llint ne;
  // // cout<<"enter the number of edges"<<endl;
  cin >> ne;
  llint **edg = new llint *[ne];
  // // cout<<"enter the values of the edges"<<endl;
  for (llint i = 0; i < ne; i++) {
    llint a, b, c;
    cin >> a >> b >> c;
    edg[i] = new llint[3];
    edg[i][0] = a - 1;
    edg[i][1] = b - 1;
    edg[i][2] = c;
  }
  // // cout<<"starting the search for the minimum spanning tree"<<endl;
  cout << use_edges(edg, ne) << endl;
  // // cout<<"program terminated"<<endl;
  return 0;
}
