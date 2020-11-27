/**
 * @file pe40.cpp
 * @author ubdussamad (ubdussamad@gmail.com)
 * @brief Project Euler Problem 40
 * @version 0.1
 * @date 2020-11-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <vector>
#include <iostream>
#include <cstring>
#define LEN 2000000

/**
 * @brief 
 * 
 * @param begin 
 * @param end 
 * @param arr 
 */
void print_l ( int begin, int end , short * arr );
void print_digits(long int x);

/**
 * @brief main function.
 * 
 * @return int 
 */
int main () {


    short x[LEN];
    memset(x ,  5 , LEN );
    long int array_ctr = 0;
    for (long int i = 1; array_ctr != 1000002 ; i++) {

        long int div = 100000000;

        if (array_ctr == 1000002) {break;}

        while ( div != 0) {

            if ( i / div != 0) {

                if (array_ctr == 1000002) {break;}

                // std::cout << (i/div)%10 << std::endl;
                if ( (i/div)%10 < 0) {
                    std::cout << "Locha" << "\n";
                }
                x[array_ctr] =  (i/div)%10;
                array_ctr++;
            }
            div /= 10;
    }
    }

    std::cout << "9th digit is: " << x[2] << std::endl;
    // std::cout << "9th term is: " << (int)x[11] << std::endl;
    std::cout << x[1-1] <<", " <<
                 x[10-1] <<", " <<
                 x[100-1] <<", " <<
                 x[1000-1] <<", " <<
                 x[10000-1] <<", " <<
                 x[100000-1] <<", " <<
                 x[1000000-1] << std::endl;

    // print_l(1000,1090 , x);s

    return 0;
}

/**
 * @brief Print a subset of a list.
 * 
 * @param begin 
 * @param end 
 * @param arr 
 */
void print_l ( int begin, int end , short * arr ) {  
    std::cout << "\n[ ";
    for (int i = begin; i < end ; i++ ) {
        std::cout << arr[i] << ", ";
    }
    std::cout << "]" << std::endl;
    return;
}



void print_digits(long int x) {
    long int div = 100000000;
    while ( div != 0) {
        if ( x / div != 0) {
            std::cout << (x/div)%10 << std::endl;
        }
        div /= 10;
    }
}