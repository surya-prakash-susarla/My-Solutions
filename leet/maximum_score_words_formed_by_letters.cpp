#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <stack>
#include <string>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long double ldouble;

// Problem :
// https://leetcode.com/problems/maximum-score-words-formed-by-letters/

class Solution {
 public:
  int __rec__(int index, int current_value, std::map<char, int> lm,
              const std::vector<std::pair<std::map<char, int>, int>>& wm) {
    if (index == wm.size()) {
      return current_value;
    }
    int not_inc = __rec__(index + 1, current_value, lm, wm);
    bool failed = false;
    std::for_each(wm[index].first.begin(), wm[index].first.end(),
                  [&failed, &lm](const std::pair<char, int>& letter) {
                    if (letter.second > lm[letter.first]) {
                      failed = true;
                      return;
                    }
                    lm[letter.first] -= letter.second;
                  });
    if (failed) {
      return not_inc;
    } else {
      int inc = __rec__(index + 1, current_value + wm[index].second, lm, wm);
      return std::max(not_inc, inc);
    }
  }

  int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters,
                    std::vector<int>& scores) {
    std::map<char, int> lm;
    std::for_each(letters.begin(), letters.end(),
                  [&lm](const char& i) { lm[i] += 1; });
    // log
    // std::cout << "printing letter count map:" << std::endl;
    // printMap(lm);
    // log
    std::vector<std::pair<std::map<char, int>, int>> wm;
    std::for_each(
        words.begin(), words.end(), [&wm, &scores](const std::string& i) {
          std::map<char, int> current_word;
          int current_score = 0;
          std::for_each(
              i.begin(), i.end(),
              [&current_word, &current_score, &scores](const char& j) {
                current_word[j] += 1;
                current_score += scores[j - 'a'];
              });
          wm.push_back({current_word, current_score});
        });
    // log
    // std::cout << "printing word letter count map: " << std::endl;
    // std::for_each(wm.begin(), wm.end(),
    //               [&](const std::pair<std::map<char, int>, int>& i) {
    //                 printMap(i.first);
    //                 std::cout << std::endl
    //                           << "score : " << i.second << std::endl;
    //               });
    // log

    return __rec__(0, 0, lm, wm);
  }

 private:
  template <typename T>
  void printMap(const std::map<T, int>& map_values) {
    std::cout << "Printing values in the map" << std::endl;
    for_each(map_values.begin(), map_values.end(),
             [](const std::pair<T, int>& value) {
               std::cout << value.first << " " << value.second << std::endl;
             });
    return;
  }
};

int main() {
  int count_words, count_letters;
  std::cout << "input -> number of words , letters : " << std::endl;
  std::cin >> count_words >> count_letters;
  std::vector<std::string> words(count_words);
  std::vector<char> letters(count_letters);
  std::vector<int> scores(26);
  std::cout << "in : data -> words -> letters " << std::endl;
  for (int i = 0; i < count_words; i++) std::cin >> words[i];
  for (int i = 0; i < count_letters; i++) std::cin >> letters[i];
  for (int i = 0; i < 26; i++) std::cin >> scores[i];
  Solution temp;
  std::cout << "Answer : " << temp.maxScoreWords(words, letters, scores)
            << std::endl;

  return 0;
}
