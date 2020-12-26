class Solution {
 public:
  vector<int> deckRevealedIncreasing(vector<int> deck) {
    if (deck.size() == 1 or deck.size() == 2)
      return deck;
    sort(deck.begin(), deck.end());
    int start_index =
        deck.size() % 2 == 0 ? deck.size() / 2 : deck.size() / 2 + 1;
    vector<int> right(deck.begin() + start_index, deck.end());
    right = deckRevealedIncreasing(right);

    if (deck.size() % 2 != 0)
      rotate(right.begin(), right.end() - 1, right.end());

    vector<int> answer;
    int i, j;
    for (i = 0, j = 0; i < start_index and j < right.size(); i++, j++) {
      answer.push_back(deck[i]);
      answer.push_back(right[j]);
    }
    while (i < start_index)
      answer.push_back(deck[i++]);
    return answer;
  }
};