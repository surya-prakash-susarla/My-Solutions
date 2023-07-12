#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;

class lottery_key {
public:
  string value;
  vector<bool> bools;
  lottery_key() {
    cin >> this->value;
    vector<bool> temp(10);
    for (llint i = 0; i < value.size(); i++) {
      temp[value[i] - '0'] = true;
    }
    bools = temp;
    //  cout<<"Boolean array of "<<value<<" is "<<endl;
    //  for(llint i=0;i<bools.size();i++)
    //    cout<<bools[i]<<"\t";
    //  cout<<endl;
  }
};

bool all_present(vector<bool> a, vector<bool> b) {
  vector<bool> temp;
  for (llint i = 0; i < 10; i++)
    temp.push_back(a[i] or b[i]);
  // cout<<"value of temp is "<<endl;
  // for(llint i=0;i<10;i++)
  //  cout<<temp[i]<<"\t";
  // cout<<endl;
  bool final_value = true;
  for (llint i = 0; i < 10; i++)
    final_value = final_value and temp[i];
  return final_value;
}

llint comb = 0;
vector<lottery_key> values;
vector<bool> visited;

void search(llint index) {
  for (llint i = 0; i < values.size(); i++) {
    //  cout<<"currently checking
    //  "<<values[index].value<<"\t"<<values[i].value<<endl;
    if (not visited[i] and i != index and
        all_present(values[index].bools, values[i].bools))
      comb += 1;
  }
  visited[index] = true;
}

int main() {
  llint n;
  cin >> n;
  for (llint i = 0; i < n; i++) {
    lottery_key temp;
    values.push_back(temp);
    visited.push_back(false);
  }
  for (llint i = 0; i < values.size(); i++)
    search(i);
  cout << comb << endl;
  return 0;
}
