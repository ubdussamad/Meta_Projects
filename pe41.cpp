#include <iostream>


bool isPrime(int n) {
    if (n <= 1) 
        return false; 
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {return false;}
    }
    return true; 
} 

bool IsPandigital(int n) {
    if (n != 9 * (int)((0x1c71c71dL * n) >> 32))
        return false;
    int flags = 0;
    while (n > 0) {
        int q = (int)((0x1999999aL * n) >> 32);
        flags |= 1 << (n - q * 10);
        n = q;
    }
    return flags == 0x3fe;
}

int main ( )  {
    for (long int i = 999999999; i > 0 ; i-=2) {
        if (IsPandigital(i) && isPrime(i)) {
            std::cout << i << std::endl;
            break; 
        }
    }
    return 0;
}


