#include <bits/stdc++.h>

// The comparator is specifically written to comply with c++17. Might cause
// errors in other verisons. C++11 version comparator struct stk_comp {
//     bool operator() ( const std::stack<int>* a , const std::stack<int>* b ) {
//         if ( a->size() == b->size() )   return a->top() > b->top() ;
//         return a->size() > b->size() ;
//     }
// };

struct stk_comp {
  bool operator()(const std::stack<int>* a, const std::stack<int>* b) const {
    if (a->size() == b->size())
      answer = a->top() > b->top();
    else
      answer = a->size() > b->size();
    return answer;
  }
  mutable bool answer = false;
};

class FreqStack {
 public:
  std::map<std::stack<int>*, int, stk_comp> rev;
  std::map<int, std::stack<int>*> main;
  int sp = 0;

  FreqStack() {}

  void push(int x) {
    if (main[x] == NULL) {
      std::stack<int>* value = new std::stack<int>();
      value->push(-1);
      value->push(sp++);
      main[x] = value;
      rev[value] = x;
    } else {
      std::stack<int>* stk = main[x];
      rev.erase(stk);
      stk->push(sp++);
      rev[stk] = x;
    }
  }

  int pop() {
    std::map<std::stack<int>*, int>::iterator it = rev.begin();
    std::stack<int>* stk = it->first;
    int answer = it->second;
    rev.erase(stk);
    stk->pop();
    rev[stk] = answer;
    return answer;
  }
};