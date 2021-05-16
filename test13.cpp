#include <string.h>

extern int i;

int main ( )  {
    volatile char a [] = "Hello world!";
    char c = a[9];
    int z = i;
    
}
