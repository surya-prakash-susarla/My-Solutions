#include <bits/stdc++.h>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& values) {
        this->values = vector<int>(values.size()+1);
        original = values;
        for(int i=0 ; i<values.size(); i++)
          init_node(i+1, values[i]);
    }
    
    void update(int index, int val) {
        int update = val - original[index];
        original[index] = val;
        index++;
        while  (index < values.size()) {
          values[index] += update;
          index = get_next(index);
        }
    }
    
    int sumRange(int left, int right) {
        return get_sum(right) - get_sum(left-1);     
    }

    void init_node ( int index , int val ) {
        while ( index < values.size() ) {
          values[index] += val;
          index = get_next(index);
        }
    }

    int get_next(int index) {
        return index + (index & -index);
    }

    int get_parent(int index) {
        return index - (index & -index);
    }

    int get_sum ( int index ) {
        index++;
        int answer = 0;
        while ( index > 0 ) {
          answer += values[index];
          index = get_parent(index);
        }
        return answer;
    }

    private:
    vector<int> original;
    vector<int> values;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
 