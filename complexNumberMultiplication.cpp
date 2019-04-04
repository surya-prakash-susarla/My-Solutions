class ComplexNumber {
    public:
    int real , imag;
    ComplexNumber ( int real , int imag ){
        this->real = real;
        this->imag = imag;
    }
    
    ComplexNumber mul ( ComplexNumber a ) {
        int real = ( this->real * a.real ) + ( 0 - this->imag  * a.imag )
            , imag = ( this->real * a.imag ) + ( this->imag * a.real );
        return ComplexNumber ( real , imag );
    }
    
    string conv ( ) {
        string answer =  to_string ( this->real )  + '+' ;
        answer = answer + to_string ( this->imag ) + 'i';
        return answer;
    }
    
};

class Solution {
public:    
    string complexNumberMultiply(string a, string b) {
        int a_plus = a.find('+') , b_plus = b.find('+');
        int a_real = stoi ( a.substr ( 0 , a_plus ) )
            , b_real = stoi ( b.substr ( 0 , b_plus ) ) ;  
        int a_img = stoi ( a.substr ( a_plus+1 , a.size()-1-a_plus ) ) 
            , b_img = stoi ( b.substr ( b_plus+1 , b.size()-1-b_plus ) ) ;
        
        ComplexNumber comp_a ( a_real , a_img) , comp_b ( b_real , b_img );
        
        ComplexNumber answer = comp_a.mul ( comp_b );
        return answer.conv();
        
    }
};