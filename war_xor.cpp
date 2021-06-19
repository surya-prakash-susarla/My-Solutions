#include <iostream>
#include <vector>
using namespace std;

typedef long long int llint;

vector<bool> sieve;

vector<bool> update_sieve(llint limit, vector<bool> sieve) {
  if (limit < sieve.size())
    return sieve;
  vector<bool> new_values(limit + 1, true);
  for (llint i = 0; i < sieve.size(); i++)
    new_values[i] = sieve[i];
  for (llint i = 0; i < limit + 1; i++)
    if (new_values[i]) {
      llint start_value = sieve.size() / i;
      if (start_value == 1 or sieve.size() <= i)
        start_value = 2;
      for (llint j = start_value; j * i < limit + 1; j++)
        new_values[i * j] = false;
    }
  return new_values;
}

bool prime_sum(llint number) {
  // cout << "Searching for " << number << endl;
  if (sieve.size() == 0) {
    vector<bool> init_vector(number + 1, true);
    init_vector[0] = false;
    init_vector[1] = false;
    sieve = init_vector;
    for (llint i = 0; i < sieve.size(); i++)
      if (sieve[i])
        for (llint j = 2; j * i < sieve.size(); j++)
          sieve[i * j] = false;
  } else {
    sieve = update_sieve(number, sieve);
  }
  // DEBUG
  // cout << "Sieve is " << endl;
  // for ( llint i=0 ; i < sieve.size() ; i++ )
  //	if ( sieve[i] )
  //		cout << i << " " ;
  // cout << endl;
  // checking if number can be formed
  for (llint i = 0; i < number; i++)
    if (sieve[i] and sieve[number - i] and (i != 2 and number - i != 2))
      return true;
  return false;
}

int main() {
  llint t;
  cin >> t;
  while (t-- > 0) {
    llint size;
    cin >> size;
    vector<llint> values(size);
    for (int i = 0; i < size; i++)
      cin >> values[i];
    llint count = 0;
    for (llint i = 0; i < size; i++)
      for (llint j = i + 1; j < size; j++)
        if (prime_sum(values[i] ^ values[j]))
          count++;
    cout << count;
    if (t > 0)
      cout << endl;
  }
  return 0;
}
