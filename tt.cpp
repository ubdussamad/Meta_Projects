#define u32 unsigned int 
#include <iostream>
#include "comlib.cpp"

bool hasFrac(float x) { // not functional for odd numbers
    bits(x);
    return !( ( *(u32*) &x) & 0x007fffff );
}

bool hasFrac2(float x) {
    return (x - (int) x) == 0;
}


int main() {
    volatile float f = 3.0000;
    std::cout << hasFrac(f) << std::endl;
    std::cout << hasFrac2(f) << std::endl;
    return 0;
}