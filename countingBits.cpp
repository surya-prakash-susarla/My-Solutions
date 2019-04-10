class Solution {
public:
    vector<int> countBits(int num) {
        if ( num == 0 ) return vector<int>(1,0);
        vector<int> answer ( num+1 ,0 );
        answer[0]=0;
        answer[1]=1;
        for ( int i=2 ; i<=num ; i++ ){
            int temp = i ;
            while ( temp >  1 ) { 
                temp = temp - (int)( 1 << ((int)log2(temp)) );
                answer[i]++;
            }
            if ( temp ==  1 )
                answer[i]++;
        }
        return answer;
    }
};