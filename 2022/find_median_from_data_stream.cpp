class MedianFinder {
 public:
  MedianFinder() {}

  inline int diff() { return abs((int)(asc.size() - dsc.size())); }

  void addNum(int num) {
    if (asc.empty() and dsc.empty()) {
      dsc.push(num);
      return;
    } else if (not dsc.empty()) {
      if (num > dsc.top())
        asc.push(num);
      else
        dsc.push(num);
    } else {
      if (num < asc.top())
        dsc.push(num);
      else
        asc.push(num);
    }

    if (diff() <= 1)
      return;

    if (asc.size() > dsc.size()) {
      while (diff() > 1) {
        dsc.push(asc.top());
        asc.pop();
      }
    } else {
      while (diff() > 1) {
        asc.push(dsc.top());
        dsc.pop();
      }
    }
  }

  double findMedian() {
    if (asc.size() == dsc.size()) {
      return ((double)(asc.top() + dsc.top())) / 2;
    } else if (asc.size() > dsc.size())
      return asc.top();
    return dsc.top();
  }

  typedef vector<int> vint;
  priority_queue<int, vint, less<int>> dsc;
  priority_queue<int, vint, greater<int>> asc;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
