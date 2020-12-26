#include <bits/stdc++.h>
using namespace std;

typedef long long int llint;

llint find(int index,
           llint current_color,
           llint seen,
           llint time,
           set<llint>& colors,
           map<llint, map<llint, llint>>& loc,
           llint& k) {
  // map<llint,map<llint,llint>>::iterator ik = loc.begin() ;
  // advance ( ik , index) ;
  // if ( ik != loc.end() )
  //     cout << " VALUE : " << ik ->first << " ";
  // cout << "INDEX : " << index << " , COLOR : " << current_color << " SEEN : "
  // << seen << " TIME : " << time << endl ;

  if (seen >= k) {
    // cout << "returing answer : " << time << endl << endl ;
    return time;
  }
  if (index == loc.size() and seen < k) {
    // cout << "LIMIT HIT" << endl;
    return numeric_limits<llint>::max();
  }

  map<llint, map<llint, llint>>::iterator it = loc.begin(), nit = loc.begin();
  advance(it, index);
  advance(nit, index + 1);

  seen += it->second[current_color];

  llint con = numeric_limits<llint>::max();

  if (nit == loc.end())
    if (seen >= k)
      return time;
    else
      return numeric_limits<llint>::max();

  if (current_color != -1)
    con = find(index + 1, current_color, seen, time + (nit->first - it->first),
               colors, loc, k);

  if (colors.size() > 0)
    for (set<llint>::iterator sit = colors.begin(); sit != colors.end();
         sit++) {
      set<llint> temp = colors;
      auto findit = temp.find(*sit);
      temp.erase(findit);
      llint cc = find(0, *sit, seen, time + (it->first), temp, loc, k);
      con = min(con, cc);
    }

  return con;
}

llint calc() {
  llint n, k;
  cin >> n >> k;
  map<llint, map<llint, llint>> loc;
  vector<llint> cl(n), co(n);
  set<llint> colors;
  for (llint i = 0; i < n; i++)
    cin >> cl[i];
  for (llint i = 0; i < n; i++) {
    cin >> co[i];
    colors.insert(co[i]);
  }
  for (llint i = 0; i < n; i++)
    loc[cl[i]][co[i]] += 1;

  llint answer = find(0, -1, 0, 0, colors, loc, k);
  return answer;
}

int main() {
  llint t;
  cin >> t;
  for (llint i = 1; i <= t; i++) {
    llint answer = calc();
    cout << "Case #" << i << ": " << answer;
    if (i < t)
      cout << endl;
  }
  return 0;
}