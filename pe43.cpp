#include <iostream>
#include <cmath>
#include <utility>
#include "comlib.cpp"



template <typename T>
bool isPentagonal (T x);

template <typename T>
T genPentagonal (T index);

long double root( long double n);
#define MAX_NUMS 5000
#include <algorithm>

int main () {

    std::cout << root(9) << std::endl;
    u64 pBuff[MAX_NUMS];
    for (u64 i = 0; i < MAX_NUMS; i++ ) pBuff[i] = genPentagonal(i+1);

    // return(0);
    u64 minDiff = 0xffffffffffffffff;

    for (u32 i=0; i <  MAX_NUMS; i++) {

        i64 pi  = pBuff[i];

        for (u32 j=i+1; j < MAX_NUMS; j++ ) {

            i64 pj = pBuff[j];

            i64 diff    = mod (pi - pj);
            i64 sum     = (pi + pj);
            
            if ( isPentagonal(diff) && isPentagonal(sum) ) {
                
                if (diff < minDiff) {
                    
                    minDiff = diff;
                    std::cout << pi << ", " << pj << "|  Sum is: " << sum << " Diff is: " << diff << std::endl;
                }
            }

        }

    }

    std::cout << minDiff << std::endl;


    
    
}

template <typename T>
T genPentagonal (T index) {
    return ( (index*(3*index - 1)) / 2 );
}


long double root( long double n){
  // Max and min are used to take into account numbers less than 1
  long double xi = n/2 + 2;
  short itr = 200;
  while (itr--) {
      xi = xi - ( ( (xi*xi) - n) / (2*(xi)) );
  }
  return xi;
}

template <typename T>
bool isPentagonal (T x) {
    long double n = (1 + root( 24 * x + 1)) /6;
    return (n - (int) n) == 0;
}


 
int mainx ( )  { 
    int j = 224536712;
    long k = 224536712;
    long long l = 224536712;

    // std::cout << "Int: " << isPentagonal(j)  << std::endl;
    std::cout << "long: " << isPentagonal(k)  << std::endl;
    std::cout << "long long: " << isPentagonal(l)  << std::endl;
}