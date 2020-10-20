#include <iostream>

int findMin(int length, int subsitution_count, std::string &str) {

    /** The loop's upper bound is set at the second last element,
     * thus we subtract 1. This is done so that, when it reaches
     * the second last element, str[i+1] dosen't goes out of bound.
     */
    int loop_upper_bound = str.size()-1;
    
    // Assumin only single pass if if subsitutin cout is still greater than zero.
    for ( int i = 0 ;           // Start from index 0
        ( i < loop_upper_bound) // We loop till upper bound.
        && subsitution_count;   // AND (logical &&) also check if we have subsitutions left. 
        i++ )                   // Increment the i index.
        
        {
        
        if (str[i]!=str[i+1] ) {
            length--;           // If we find diffrent chars, it means the length should be one less the original
            i+=2;               // If we find find different chars, skip ahead two chars as we check the next pair of chars.
        
        }
    
    }
    
    return length;              // Finally return the length
    
}

int main (void) {
    std::string k = "aabc";

    std::cout << findMin(k.size(),1,k) << std::endl;
    return( 0 );

}