#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

// DEBUG PRINT METHOD FOR LIST
// void print ( list<char> values ) {
//     for ( auto i : values )
//         cout << i << " " ;
//     cout << endl ;
//     return;
// }

class Solution {
 public:
  string customSortString(string target, string input) {
    // DEBUG
    // cout << "Target : " << target << endl ;
    // cout << "Input : " << input << endl ;
    // DEBUG

    vector<int> target_indices(26, -1);
    for (int i = 0; i < target.size(); i++)
      target_indices[target[i] - 'a'] = i;

    vector<int> last_known(26, -1);

    list<char> answer;

    for (int i = 0; i < input.size(); i++) {
      // check if input character is in target
      if (target_indices[input[i] - 'a'] != -1) {
        int insertion_index = -1;

        // Find index to insert the current element into the list
        if (last_known[input[i] - 'a'] != -1) {
          // Element already exists in the final list
          insertion_index = last_known[input[i] - 'a'];
        } else {
          // Find the nearest element in the final list
          for (int j = target_indices[input[i] - 'a'] + 1; j < target.size();
               j++)
            if (last_known[target[j] - 'a'] != -1) {
              insertion_index = last_known[target[j] - 'a'];
              break;
            }
        }
        int last_index;
        if (insertion_index == -1) {
          answer.push_back(input[i]);
          last_index = answer.size() - 1;
        } else {
          auto k = answer.begin();
          advance(k, insertion_index);
          answer.insert(k, input[i]);
          last_index = insertion_index;
          // Update indices
          for (int j = target_indices[input[i] - 'a'] + 1; j < target.size();
               j++)
            if (last_known[target[j] - 'a'] != -1)
              last_known[target[j] - 'a'] += 1;
        }
        last_known[input[i] - 'a'] = last_index;

        // DEBUG
        // cout << "element : " << input[i] << " , insertion index : " <<
        // insertion_index << endl; cout << "last known : " <<
        // last_known[input[i]-'a'] << endl; cout << "answer : " ; print (
        // answer ); cout << endl; DEBUG

      } else {
        answer.push_back(input[i]);
      }
    }

    string final_answer;
    for (auto i = answer.begin(); i != answer.end(); i++)
      final_answer = final_answer + *i;

    return final_answer;
  }
};

int main() {
  string a, b;
  cin >> a;
  cin >> b;
  Solution temp;
  string answer = temp.customSortString(a, b);
  cout << answer << endl;
  return 0;
}