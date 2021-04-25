class Solution {
public:

    void shift ( int start , int shift_size , vector<vector<int>>& input ) {
        int x = start ; 
        int y = start ;

        constexpr int unin = numeric_limits<int>::min();

        int buffer = unin ;
        // row - l2r
        for ( int col = start ; col <= y + shift_size ; col++ ) {
            if ( buffer == unin )  {
                buffer = input[x][col];
            } else {
                swap ( buffer , input[x][col] );
            }
        }

        // col - t2b
        for ( int row = x+1 ; row <= x + shift_size ; row++ ) {
            swap ( buffer , input[row][y+shift_size] );
        }

        // row - r2l
        for ( int col = y+shift_size-1 ; col >= y ; col-- ) {
            swap ( buffer , input[x+shift_size][col] );
        }

        // col - b2t
        for ( int row = x+shift_size-1 ; row >= x ; row-- ) {
            swap ( buffer , input[row][y]);
        }

        return;
    }


    void rotate(vector<vector<int>>& matrix) {
        
        const int dim = matrix.size() ; 
        int dist = dim % 2 == 1 ? 2 : 1 ;

        for ( int i = dim/2-1 ; i>=0 ; i-- ) {
            for ( int k = 0 ; k < dim ; k++ )
                shift ( i , dist , matrix );
            dist +=  2;
        }

        return;      
    }
};