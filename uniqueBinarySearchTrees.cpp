// WARNING : TLE ( Optimize ) 

class Solution {
public:
    int build ( int root_index , int start_index , int end_index ){
        if ( end_index - start_index <= 0 ) return 1;
        int lescom = 0 , highcom = 0 ;
        for ( int i=root_index-1 ; i>=start_index ; i-- )
                lescom += build(i , start_index , root_index-1 );
        for ( int i=root_index+1 ; i<=end_index ; i++ )
                highcom += build(i , root_index+1 , end_index );
        if ( lescom !=0 and highcom !=0 )   return lescom*highcom;
        return max(lescom,highcom);
    }
    
    int numTrees(int n) {
        int total =0 ;
        for ( int i=0 ; i<n ; i++ )
            total += build ( i , 0 , n-1 );
        return total; 
    }
};