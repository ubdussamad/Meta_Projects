#include <cstdio>
#include <cstdlib>
#include <string.h>


void str2 (char * str){
  
  memcpy(str , "Hi!" , 3);
}

int main () {
  char buff[1] = {'a'};
  str2(buff);
  printf("Str1: %s\n", buff);
  return (0);
}

