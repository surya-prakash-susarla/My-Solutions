#include <iostream>
#include <vector>

using namespace std;

typedef long long int llint;
llint n, cl, cr;

class town {
public:
  int data;
  vector<llint> cons;

  void add_con(llint cit) {
    cons.push_back(cit);
    return;
  }
};

llint depth_counter(llint, bool, llint, vector<town> &, vector<bool> &);

llint cost_counter(vector<town> cities, vector<bool> covered) {
  // cout<<"inside the cost counter function"<<endl;
  bool all_visited = false;
  if (cr > cl)
    return (n - 1) * cl;
  llint cost = 0;
  while (not all_visited) {
    llint index;
    for (llint i = 1; i < n; i++)
      if (not covered[i])
        index = i;
    // cout<<"CURRENT INDEX IS "<<index<<endl;
    cost = cost + depth_counter(index, true, 0, cities, covered);
    // cout<<"cost after traversal from "<<index <<"is "<<cost<<endl;
    all_visited = true;
    for (llint i = 1; i < n; i++)
      if (not covered[i])
        all_visited = false;
  }
  return cost;
} // end of cost_counter function

llint depth_counter(llint index, bool build_library, llint cost,
                    vector<town> &cities, vector<bool> &covered) {
  // cout<<"the current index is "<<index<<endl;
  if (build_library) {
    // cout<<"building a library at "<<index<<endl;
    cost = cost + cl;
    // cout<<"cost is "<<cost<<endl;
  } else {
    // cout<<"road built at "<<index <<endl;
    cost = cost + cr;
    // cout<<"cost is "<<cost<<endl;
  }
  covered[index] = true;
  llint next_index = -1;
  for (llint i = 0; i < cities[index].cons.size(); i++)
    if (not covered[cities[index].cons[i]]) {
      next_index = cities[index].cons[i];
      // cout<<"the index after "<<index <<" is " <<next_index<<endl;
      cost = depth_counter(next_index, false, cost, cities, covered);
    }
  // cout<<"final cost returned from "<<index<<" is "<<cost<<endl;
  return cost;
} // end of depth counter function

int main() {
  llint t;
  // cout<<"enter the number of test cases "<<endl;
  cin >> t;
  while (t-- > 0) {
    llint l;
    // cout<<"enter the number of cities , links , cost to build library and
    // cost of road "<<endl;
    cin >> n >> l >> cl >> cr;
    n += 1;
    vector<bool> covered(n, false);
    vector<town> cities(n);
    // for(llint i=1;i<n;i++)
    //  cities[i].push_back(new town);
    // cout<<"enter the links "<<endl;
    for (llint i = 0; i < l; i++) {
      llint a, b;
      cin >> a >> b;
      cities[a].add_con(b);
      cities[b].add_con(a);
    }
    // cout<<"the cost is "<<endl;
    cout << cost_counter(cities, covered);
    if (t > 0)
      cout << endl;
  } // end of while loop
  return 0;
}
