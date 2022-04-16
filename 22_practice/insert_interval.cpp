class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        typedef vector<int> vint;
        typedef vector<vint> vvint;
        
        bool inserted = false;
        for(auto it = intervals.begin(); it != intervals.end(); it++){
            const vint& temp = *it;
            if ( temp[0] == newInterval[0] ){
                if ( temp[1] > newInterval[1] ){
                    intervals.insert(it, newInterval);
                } else {
                    intervals.insert(next(it), newInterval);
                }
                inserted = true;
                break;
            } else if ( temp[0] > newInterval[0] ){
                intervals.insert(it, newInterval);
                inserted = true;
                break;
            }
        }
        
        if ( not inserted )
            intervals.push_back(newInterval);
        
        vvint answer;
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for(int i=1 ; i<intervals.size(); i++){
            if ( intervals[i][0] <= end ){
                end = max(end, intervals[i][1]);
            } else {
                answer.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        answer.push_back({start, end});
        
        return answer;
    }
};

