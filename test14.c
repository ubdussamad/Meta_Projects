#include <stdio.h>
#include <stdlib.h>
int main ( void )  {
  // FILE *fd, *fd2, *fd3;
  // fd  = fopen("test.txt", "r");
  // fd2 = fopen("test.txt", "r");
  // fd3 = fopen("test.txt", "r");
  // int fd4 = open("test.txt");
  // printf("\nThe fd is: %d and fd2 is: %d and finally fd3 : %d.\n" , fd->_fileno , fd2->_fileno , fd4 ); 
  char buffer[100];
  fgets( buffer, 20, stdin ); 
  printf( "%s\n" , buffer );
  return(0);

}
