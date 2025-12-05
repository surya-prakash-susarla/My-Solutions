class LRUCache {
 public:
  LRUCache(int capacity) {
    n = capacity;
    t = 0;
  }

  int get(int key) {
    // cout << "getting key : " << key << endl;
    auto it = contents.find(key);
    if (it != contents.end()) {
      current[key] = ++t;
      ordering.push({t, key});
      // print_contents();
      return it->second;
    }
    // cout << "not found" << endl;
    return -1;
  }

  void clean() {
    while (not ordering.empty()) {
      pint temp = ordering.top();
      ordering.pop();
      // cout << "current time chosen : " << temp.second << " , key : " <<
      // temp.first << " actual : " << current[temp.second] << endl;
      if (temp.first == current[temp.second]) {
        // cout << "picking key to erase : " << temp.second << endl;
        contents.erase(temp.second);
        return;
      }
    }
  }

  void print_contents() {
    cout << "contents : " << endl;
    for (auto i : contents)
      cout << i.first << " " << i.second << endl;
    cout << "times : " << endl;
    for (auto i : current)
      cout << i.first << " " << i.second << endl;

    if (ordering.empty())
      return;
    cout << "ordering : " << endl;
    auto temp = ordering;
    for (; not temp.empty(); temp.pop()) {
      auto i = temp.top();
      cout << i.first << " " << i.second << endl;
    }
  }

  void put(int key, int value) {
    // cout << "putting key : " << key << " , value : " << value << endl;
    if (contents.contains(key)) {
      contents[key] = value;
      current[key] = ++t;
      ordering.push({t, key});
      return;
    }
    if (contents.size() == n) {
      clean();
    }
    contents[key] = value;
    current[key] = ++t;
    pint temp = {t, key};
    // cout << "pushing into ordering : " << temp.first << " " << temp.second <<
    // endl;
    ordering.push(temp);
    // print_contents();
  }

  int n;
  int t = 0;
  map<int, int> contents;
  map<int, int> current;

  typedef pair<int, int> pint;
  priority_queue<pint, vector<pint>, greater<pint>> ordering;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
