#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define NULL_STRING string("")

vector<pair<string, string>> memo;

string substring(string input, int start, int end) {
  string temp = NULL_STRING;
  for (int i = start; i < end; i++)
    temp = temp + input[i];
  return temp;
}

int distinct(string input) {
  set<char> temp;
  for (char c : input) {
    temp.insert(c);
  }
  return temp.size();
}

string remove_instances(string input, char c) {
  string temp = NULL_STRING;
  for (char i : input)
    if (i != c)
      temp = temp + i;
  return temp;
}

int main() {
  string input_value;
  getline(cin, input_value);
  int k;
  cin >> k;
  for (int i = 0; i < input_value.size(); i++)
    memo.push_back(make_pair(NULL_STRING, NULL_STRING));
  int index = input_value.size() - 1;
  memo[index].first = NULL_STRING;
  memo[index].second = NULL_STRING + input_value[index];

  index = index - 1;

  while (index >= 0) {
    string next_greatest = memo[index + 1].second;
    if (memo[index + 1].first.size() > next_greatest.size())
      next_greatest = memo[index + 1].first;
    memo[index].first = next_greatest;
    string second_base = memo[index + 1].second;
    char current_char = input_value[index];
    if (distinct(current_char + second_base) > k) {
      int i = -1;
      for (i = second_base.size() - 1; i >= 0; i--)
        if (second_base[i] != current_char)
          break;
      char faulty = second_base[i];
      second_base = substring(second_base, 0, i);
      second_base = remove_instances(second_base, faulty);
    }
    memo[index].second = current_char + second_base;
    index--;
  }
  string longest_substring = NULL_STRING;
  for (int i = 0; i < memo.size(); i++) {
    if (memo[i].first.size() > longest_substring.size())
      longest_substring = memo[i].first;
    if (memo[i].second.size() > longest_substring.size())
      longest_substring = memo[i].second;
  }

  cout << "The longest substring is " << longest_substring << endl;

  return 0;
}
