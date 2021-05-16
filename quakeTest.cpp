#include <cmath>
#include <iostream>
#include<bits/stdc++.h>
#include <limits>
#define u32 unsigned int

void bits(float x);
void bits(u32 x);

typedef unsigned short v4si __attribute__ ((vector_size (4)));
int main () {
    v4si a, b, c;
    u32* i = (u32 *) &a;
    *i = 0x0000eeee;

    u32* j = (u32 *) &b;
    *j = 0x00001111;

    u32* k = (u32 *) &c;
    *k = 0x00000000;
    
    c = a + b;
    // // bits(*k);
    char out[33];
    sprintf(out, "%.8b", *k);
    std::cout << out << std::endl;
    // std::cout << c[0] << " " << c[1] << " " << std::endl;
}

void bits(u32 x) {
    u32 s = sizeof(u32) << 3;
    std::string buff = "\n";
    for ( int i = 0; i < s; i++){
        if (!(i%16)) {buff+="-";}
        if (!(i%4)) {buff+=" ";}
        buff += (1U<<i)  & x ? "1" : "0";
    }
    std::reverse(buff.begin(),buff.end());
    std::cout <<  buff << std::endl;
}

int ffltest ()  {
        float num  = 4.568;
        float stdlog = std::log2f( num );
        float nu =( (float) ( (*(unsigned int*)&num) ) )/ (float)(1<<23);
        float lg = ( nu ) + 0.0683365 - 127;
        std::cout << "Average diff is: " << std::abs(stdlog - lg) << std::endl;
        std::cout << "stdlog is: " << stdlog << "| mylog: " << lg << std::endl;
        return 0;
}

int fastFloatLog ( )  {

    float min_diff_chi = 0.0;
    float min_diff = 1.0;

    for ( float chi = 0.0F ; chi < 1.0F ; chi+=0.000001) {
        
        float avg_diff = 0.0;

        for ( float num = 0.1F ; num < 100.0 ; num+=0.5F ) {
        float stdlog = std::log2f( num );
        float nu =( (float) ( (*(unsigned int*)&num) ) )/ (float)(1<<23);
        float lg = ( nu ) + chi - 127;
        avg_diff += std::abs(stdlog - lg);

        }

        avg_diff /= 9900;
        // std::cout << "Avg diff: " << avg_diff << std::endl;
        if (avg_diff < min_diff) {min_diff = avg_diff;min_diff_chi = chi;}
    }

    std::cout << min_diff_chi << " | Min diff is: " << min_diff << std::endl;
    return 0;

}

void bits(float x) {
    std::cout << "Bits for " << x << " are: ";
    for (int i=0; i < (sizeof(x) * 8) ; i++ ) {
        if (!(i%4)) {
            std::cout << "-";
        }

        if (!(i%8)) {
            std::cout << "  ";
        }
        if ( (*(int *) &x) & (1U << i) ) {
            std::cout << '1';
        }
        else {
            std::cout << '0';
        }
    }
    std::cout << std::endl;
}