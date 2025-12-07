class BrowserHistory {
 public:
  BrowserHistory(string homepage) {
    values.push_back(homepage);
    index = 1;
  }

  void visit(string url) {
    if (index == values.size()) {
      values.push_back(url);
      index++;
      return;
    }
    values[index] = url;
    values.erase(values.begin() + index + 1, values.end());
    index++;
  }

  string back(int steps) {
    while (index > 1 and steps) {
      index--;
      steps--;
    }
    return values[index - 1];
  }

  string forward(int steps) {
    while (index != values.size() and steps) {
      index++;
      steps--;
    }
    return values[index - 1];
  }

  int index = 0;
  vector<string> values;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
