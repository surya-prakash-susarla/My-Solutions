#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <utility>
#include <limits>
#include <queue>
#include <cmath>
#include <list>
#include <string>
#include <cstdio>
#include <numeric>
#include <stack>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
       typedef ListNode node;
       stack<int> full_values;
       node* temp = head;
       while(temp) {
           full_values.push(temp->val);
           temp = temp->next;
       } 
       stack<int> fh;
       stack<int> sh;

        int n = full_values.size();

       for ( int i=0 ;  i<n/2  ; i++ ) {
           fh.push(full_values.top());
           full_values.pop();
       }

       while(not full_values.empty()) {
           sh.push(full_values.top());
           full_values.pop();
       }

        {
            stack<int> temp;
            for ( ; not fh.empty() ; fh.pop() )
                temp.push(fh.top());
            fh = temp;
        }


    //    cout << "fh size : " << fh.size() << endl;
    //    cout << "sh size : " << sh.size() << endl;
       
    //    cout << "contents of fh : " << endl;
    //    {
    //        for ( stack<int> temp = fh ; not temp.empty() ;  temp.pop() )
    //        cout << temp.top() << " ";
    //        cout << endl;
    //    }
    //    cout << "contents of sh : " << endl;
    //    {
    //        for ( stack<int> temp = sh ; not temp.empty() ; temp.pop() )
    //        cout << temp.top() << " ";
    //        cout << endl;
    //    }

        long long int answer = numeric_limits<int>::min();

        while ( not fh.empty() ) {
            answer = max(answer, (long long int)(fh.top() + sh.top()) );
            fh.pop();
            sh.pop();
        }

        return answer;
    }
};

int main() {

    ios_base::sync_with_stdio(false); 


    return 0;
}

