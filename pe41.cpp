#include <iostream>

int countDigit(long long n)
{
    int count = 0;
    while (n != 0) 
    {
        n = n / 10;
        ++count;
    }
    return count;
}

bool check_pan(long long number) {
    int length = countDigit(number);
    
    using namespace std;
    int i=0;
    int grid[length];
    while (number>0) {
        grid[i]=number%10;
        number=number/10;
        i++;
    }
    int summation=0, factorial=1;
    int summation1=0, factorial1=1;
    for (int i=0; i<=length-1; i++) {
        factorial=factorial*grid[i];//counts product of digits and factorial of length
        factorial1=factorial1*(i+1);
        summation=summation+grid[i];//counts sum of digits and summation of integers to length
        summation1=summation1+(i+1);
    }
    if ((factorial==factorial1) and (summation==summation1) and (factorial!=0)) return true;
    else return false;
}

/**
 * @brief Very Poor implimentation,
 * but gets the job done.
 * 
 * @param n 
 * @return true 
 * @return false 
 */
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
        if (check_pan(i) && isPrime(i)) {
            std::cout << i << std::endl;
            break; 
        }
    }
    return 0;
}


