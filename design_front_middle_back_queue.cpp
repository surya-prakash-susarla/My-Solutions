class FrontMiddleBackQueue {
 public:
  list<int> first;
  list<int> second;

  void print() {
    // cout << "contents of first queue : " << endl;
    // for ( auto i : first )  cout << i << " ";
    // cout << endl << " contents of second queue : " << endl;
    // for ( auto i : second ) cout << i << " ";
    // cout << endl;
  }

  void balance() {
    int first_size = first.size();
    int second_size = second.size();
    // cout << "balancing stuff " << endl;

    if ((first_size + second_size) % 2 == 0) {
      while (first.size() != second.size()) {
        if (first.size() > second.size()) {
          second.push_front(first.back());
          first.pop_back();
        } else if (second.size() > first.size()) {
          first.push_back(second.front());
          second.pop_front();
        }
      }
    } else {
      int req_size = ((first_size + second_size) / 2) + 1;
      while (first.size() != req_size) {
        if (first.size() > req_size) {
          second.push_front(first.back());
          first.pop_back();
        } else {
          first.push_back(second.front());
          second.pop_front();
        }
      }
    }
  }

  FrontMiddleBackQueue() {}

  void pushFront(int val) {
    // cout << "pushing : "<< val << " to front" << endl;
    first.push_front(val);
    balance();
    print();
  }

  void pushMiddle(int val) {
    if (first.size() > second.size()) {
      // cout << "uneven list, pushing in front" << endl;
      int temp = first.back();
      first.pop_back();
      first.push_back(val);
      first.push_back(temp);
      balance();
      print();
    } else {
      // cout << "both lists are even, loading the first one" << endl;
      first.push_back(val);
      balance();
      print();
    }
  }

  void pushBack(int val) {
    second.push_back(val);
    balance();
    // cout << "pushing : " << val << " to back" << endl;
    print();
  }

  int popFront() {
    if (first.empty())
      return -1;
    int return_value = first.front();
    first.pop_front();
    balance();
    // cout << "removing value in the front, return value : " << return_value;
    print();
    return return_value;
  }

  int popMiddle() {
    if (first.size() > second.size()) {
      // cout << "uneven list , returning from front" << endl;
      int return_value = first.back();
      first.pop_back();
      balance();
      print();
      return return_value;
    } else {
      if (first.empty())
        return -1;
      // cout << "even list , prioritizing first" << endl;
      int return_value = first.back();
      first.pop_back();
      balance();
      print();
      return return_value;
    }
  }

  int popBack() {
    if (second.empty()) {
      // cout << "second is empty" << endl;
      if (first.empty())
        return -1;
      int return_value = first.back();
      first.pop_back();
      // cout << "returning from back, value : " << return_value << endl;
      balance();
      print();
      return return_value;
    } else {
      int return_value = second.back();
      second.pop_back();
      // cout << "returning from back of second, value : " << return_value <<
      // endl;
      balance();
      print();
      return return_value;
    }
  }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
