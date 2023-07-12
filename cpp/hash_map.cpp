#include <iostream>
#include <map>
#include <utility>

using namespace std;

class node {
public:
  char value;
  map<char, node &> connections;

  node(char c) { this->value = c; }

  void find_exists(char value) {
    cout << (this->connections).count(value) << endl;
  }
};

int main() {
  /*
  node temp1 ( 'z' );
  node temp2 ( 'y' );

  node main_value ( 'a' ) ;
  main_value.connections.insert ( make_pair ( 'z' , temp1 ) ) ;
  main_value.connections.insert ( make_pair ( 'y' , temp2 ) ) ;

  main_value.find_exists ( 'z' ) ;


  map < char , int > values ;
  pair<char,int> temp1 = make_pair ( 'a' , -1 ) ;
  pair<char,int > temp2 = make_pair ( 'b' , -2 ) ;

  values.insert ( temp1 ) ;
  values.insert ( temp2 ) ;

  cout << "the size is " << values.size() << endl ;

  for ( map<char,int>::iterator it = values.begin() ; it!=values.end() ; it++ )
          cout << it->first << " "<< it->second << endl;

  /*
  char temp ;
  cin>> temp;


  cout << values.count( temp ) <<endl;

  if ( values[temp] )
          cout << values[temp] << endl ;
  else
          cout << "done"<<endl;
  */

  string temp = "surya";
  cout << temp.size() << endl;
  return 0;
}