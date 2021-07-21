#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

#define u32 unsigned int
#define i32 int
#define i64 long long
#define u64 long long unsigned


template <typename T>
void printArray( u32 start, u32 width , T* arr);

template <typename T>
void printArray( u32 start,u32 width , T* arr) {
    std::cout << "[ ";
    for (u32 i = start ; i < (start+width) ; i++ ) {
        std::cout << (arr)[i] << ", " ;
    }
    std::cout << "]" << std::endl;
}

template <typename T>
inline T mod ( T x) {
    return x<0 ? -x : x;
}


template <typename T>
T genPentagonal (T index) {
    return ( (index*(3*index - 1)) / 2 );
}
template <typename T>
T genTriangular (T index) {
    return ( (index*(index + 1)) / 2 );
}
template <typename T>
T genHexagonal (T index) {
    return index*(2*index - 1);
}

template <typename T>
bool isPentagonal (T x) {
    long double n = (1 + std::sqrt( 24 * x + 1)) /6;
    return (n - (int) n) == 0;
}




void bits(float x) {
    std::cout << "Bits for " << x << " are: ";
    std::string buff;
    for (int i=0; i < (sizeof(x) * 8) ; i++ ) {
        if (!(i%23)) {
            buff += "-";
        }

        // if (!(i%8)) {
        //     buff += "-";
        // }
        if ( (*(int *) &x) & (1U << i) ) {
            buff += '1';
        }
        else {
            buff += '0';
        }
    }
    std::reverse(buff.begin() , buff.end() );

    std::cout << buff << std::endl;
}