class HitCounter {
 public:
  HitCounter() {}

  void prune() {
    int latest = (*hits.rbegin()).first;
    prune(latest);
  }

  void prune(int latest) {
    auto it = hits.upper_bound(latest - 300);
    hits.erase(hits.begin(), it);
  }

  void hit(int timestamp) {
    auto it = hits.find(timestamp);
    if (it == hits.end()) {
      if (not hits.empty()) {
        pair<int, int> prev = (*hits.rbegin()).second;
        hits[timestamp] = {1, prev.first + prev.second};
      } else {
        hits[timestamp] = {1, 0};
      }
    } else {
      it->second.first++;
    }
    prune();
  }

  int getHits(int timestamp) {
    prune(timestamp);

    if (hits.empty())
      return 0;

    auto end_it = hits.rbegin();
    auto begin_it = hits.upper_bound(timestamp - 300);

    int answer =
        end_it->second.first + end_it->second.second - begin_it->second.second;

    return answer;
  }

  map<int, pair<int, int>> hits;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
