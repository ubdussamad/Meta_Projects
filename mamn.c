#include <stdio.h>

int palindrome (  long int num );

int main( void ) {
  long int largest= 0;
  for ( long int i = 10000; i < 998001; i++ ) {
    if ( palindrome(i) ) {
      largest = i;
    }
  }
  printf("The Largest number is: %li\n" , largest);
  return(0);
}

int palindrome (  long int num ) {
  long int reversed = 0;
  long int num_cpy = num;
  int remainder;
  while ( num > 0 ) {
    remainder = num % 10;
    reversed  = reversed* 10 + remainder;
    num /= 10;
  }
  return(  reversed == num_cpy ? 1 : 0 );
}

    
