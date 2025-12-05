class Allocator {
 public:
  Allocator(int n) { values = vector<int>(n, 0); }

  pair<bool, int> is_valid(int index, int size) {
    // cout << "searching for space at : " << index << " , size : " << size <<
    // endl;
    if (index + size - 1 >= values.size())
      return {true, values.size()};

    int i;
    bool failed = false;
    for (i = index; i < index + size; i++) {
      if (values[i] != 0) {
        failed = true;
        break;
      }
    }

    pair<bool, int> answer = {failed, i};
    // cout << "answer : " << answer.first << " " << answer.second << endl;
    return answer;
  }

  int allocate(int size, int mID) {
    // cout << endl << "allocating mem : " << size << " id : " << mID << endl;
    for (int i = 0; i < values.size(); i++) {
      pair<bool, int> result = is_valid(i, size);
      if (!result.first) {
        // cout << "filling from : " << i << " " << result.second << endl;
        for (int j = i; j < result.second; j++)
          values[j] = mID;

        // cout << "result after allocation : " << endl;
        // for ( auto j : values ) cout << j << " " ;
        // cout << endl;

        return i;
      } else {
        i = result.second;
      }
    }
    return -1;
  }

  int freeMemory(int mID) {
    int count = 0;
    for (int& i : values)
      if (i == mID) {
        i = 0;
        count++;
      }
    // cout << endl << "freed count : " << count << " , id : " << mID << endl;
    return count;
  }

  vector<int> values;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
