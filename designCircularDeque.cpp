#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque {
 public:
  vector<int> front, back;
  int size;
  /** Initialize your data structure here. Set the size of the deque to be k. */
  MyCircularDeque(int k) { size = k; }

  /** Adds an item at the front of Deque. Return true if the operation is
   * successful. */
  bool insertFront(int value) {
    if (front.size() + back.size() < size) {
      front.push_back(value);
      return true;
    }
    return false;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is
   * successful. */
  bool insertLast(int value) {
    if (front.size() + back.size() < size) {
      back.push_back(value);
      return true;
    }
    return false;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is
   * successful. */
  bool deleteFront() {
    if (front.size() + back.size() == 0)
      return false;
    for (int it = front.size() - 1; it > -1; it++) {
      front.erase(front.begin() + it);
      return true;
    }
    for (auto it = back.begin(); it != back.end(); it++) {
      back.erase(it);
      return true;
    }
    return false;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is
   * successful. */
  bool deleteLast() {
    if (front.size() + back.size() == 0)
      return false;
    for (int it = back.size() - 1; it > -1; it++) {
      back.erase(back.begin() + it);
      return true;
    }
    for (auto it = front.begin(); it != front.end(); it++) {
      front.erase(it);
      return true;
    }
    return false;
  }

  /** Get the front item from the deque. */
  int getFront() {
    for (auto it = front.rbegin(); it != front.rend(); it++)
      return *it;
    for (auto it = back.begin(); it != back.end(); it++)
      return *it;
    return -1;
  }

  /** Get the last item from the deque. */
  int getRear() {
    for (auto it = back.rbegin(); it != back.rend(); it++)
      return *it;
    for (auto it = front.begin(); it != front.end(); it++)
      return *it;
    return -1;
  }

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty() {
    if (front.size() != 0 or back.size() != 0)
      return false;
    return true;
  }

  /** Checks whether the circular deque is full or not. */
  bool isFull() {
    if (front.size() + back.size() == size)
      return true;
    return false;
  }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */