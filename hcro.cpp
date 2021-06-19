#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long int n, rels, cl, cr, num_vis = 0;
vector<vector<long long int>> ar;
bool *vis;
bool all_visited() {
  // cout<<"checking if all nodes are visited using the function"<<endl;
  /*for(int i=0;i<n;i++)
          if(not vis[i])
                  return false;
  return true;*/
  if (num_vis < n)
    return false;
  return true;
}
int not_vis() {
  // cout<<"searching for unvisited nodes using the function"<<endl;
  for (int i = 0; i < n; i++)
    if (not vis[i])
      return i;
  return -1;
}
void connected_paths(vector<long long int> &paths, int row) {
  // cout<<"identifying connected paths using function"<<endl;
  // cout<<"current pos = "<<row<<endl;
  paths.push_back(row);
  vis[row] = true;
  num_vis += 1;
  for (int i = 0; i < ar[row].size(); i++) {
    if (not vis[ar[row][i]])
      connected_paths(paths, ar[row][i]);
  }
}
int main() {
  int q;
  // cout<<"enter the number of queries"<<endl;
  cin >> q;
  while (q-- > 0) {
    //	cout<<"enter the number of cities , roads , cost of library and
    //roads"<<endl;
    cin >> n >> rels >> cl >> cr;
    ar.resize(n);
    //	cout<<"enter the road combinations"<<endl;
    for (int i = 0; i < rels; i++) {
      int g, h;
      cin >> g >> h;
      //	cout<<"inserting elements by checking if they are already
      //present in the vector of the node"<<endl;
      if (ar[g - 1].size() == 0 or ar[h - 1].size() == 0 or
          find(ar[g - 1].begin(), ar[g - 1].end(), h - 1) == ar[g - 1].end()) {
        ar[g - 1].push_back(h - 1);
        // if(find(ar[h-1].begin(),ar[h-1].end(),g-1)==ar[h-1].end())
        ar[h - 1].push_back(g - 1);
      }
    }
    /*	cout<<"the current adjacency list is "<<endl;
            for(int i=0;i<n;i++){
                    for(int j=0;j<ar[i].size();j++)
                            cout<<ar[i][j]<<" ";
                    cout<<endl;
            }
    */
    vis = new bool[n];
    if (cr > cl)
      cout << n * cl << endl;
    else {
      //	cout<<"checking for empty nodes"<<endl;
      long long int toc = 0;
      for (int i = 0; i < n; i++) {
        vis[i] = false;
        if (ar[i].size() == 0) {
          toc += cl;
          vis[i] = true;
          num_vis += 1;
        }
      }
      //	cout<<"completed checking for empty nodes"<<endl;
      //	cout<<"cost after checking for empty nodes is "<<toc<<endl;
      while (not all_visited()) {
        //		cout<<"Inside while loop checking for connected regions
        //using dfs"<<endl;
        long long int ind = not_vis();
        //		cout<<"search starts from "<<ind<<endl;
        vector<long long int> paths;
        connected_paths(paths, ind);
        //		vector<int>::iterator it;
        //		for(it=paths.begin();it!=paths.end();it++)
        //			cout<<*it<<" ";
        //		cout<<endl;
        toc += ((paths.size() - 1) * cr) + cl;
      }
      cout << toc << endl;
      //    cout<<"the final number of covered nodes are "<<num_vis<<endl;
    }

    //      TAKE THIS AWAY IF GETTING WA
    //	for(int i=0;i<n;i++)
    //		ar[i].clear();

    ar.clear();
  }
  return 0;
}
