class Solution {
public:
    vector<int> findDuplicates(vector<int>& input) {
        int i=0;
        vector<int> answer;
        while ( i<input.size() ){
            if ( input[i] == -1 or input[i] == i+1 ){
                i++;
            } else {
                int iocn = input[i]-1;
                if ( input[iocn] == input[i] ){
                    answer.push_back(input[i]);
                    input[i] = -1;
                    i++;
                } else {
                    swap(input[iocn], input[i]);
                }
            }
        }
        return answer;
    }
};
