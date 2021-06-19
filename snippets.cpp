
// string searching method
cout << "enter string" << endl;
string s;
cin >> s;
cout << "Enter a string" << endl;
string c;
cin >> c;
if (s.find(c) != string::npos)
  cout << "found" << endl;
else
  cout << "shit" << endl;

// vector searching and index finding method
vector<int> temp;
for (int i = 0; i < 5; i++) {
  int t;
  cin >> t;
  temp.push_back(t);
}
cout << "Enter an element to be searched" << endl;
int se;
cin >> se;
if (find(temp.begin(), temp.end(), se) != temp.end())
  cout << "found at " << find(temp.begin(), temp.end(), se) - temp.begin()
       << endl;
else
  cout << "not found " << endl;

// stack methods
stack<int> temp;
for (int i = 0; i < 5; i++) {
  int t;
  cin >> t;
  temp.push(t);
}
cout << "top is " << temp.top() << endl;
cout << "the data is " << endl;
while (not temp.empty()) {
  cout << temp.top() << endl;
  temp.pop();
}