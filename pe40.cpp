#include <vector>
#include <iostream>
#include <cstring>
#define LEN 1000000
void print_l ( int begin, int end , char * arr );
int main () {
    char x [LEN+2000];
    long int ctr = 0;
    memset(x , 'x' , LEN+2000);
    for (long long int i = 0; i < LEN; i++) {
        if (ctr == LEN) {break;}
        long long int iCpy = i;
        int div = 1000000;
        while ( (div*10) != 0  ) {
            if ( (iCpy/div) != 0) {
                x[ctr] = (char)(iCpy/div) % 10;
                ctr++;
                if (ctr == LEN) {break;}
            }
            div/=10;
        }

    }
    // std::cout << "12th term is: " << (int)x[11] << std::endl;
    std::cout << (int)x[0-0] <<", " <<
                 (int)x[10-1] <<", " <<
                 (int)x[100-1] <<", " <<
                 (int)x[1000-1] <<", " <<
                 (int)x[10000-1] <<", " <<
                 (int)x[100000-1] <<", " <<
                 (int)x[1000000-1] << std::endl;

    print_l(200,230 , x);

    return 0;
}


void print_l ( int begin, int end , char * arr ) {  
    std::cout << "\n[ ";
    for (int i = begin; i < end ; i++ ) {
        std::cout << (int) arr[i] << ", ";
    }
    std::cout << "]" << std::endl;
    return;
},