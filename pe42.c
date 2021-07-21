
#include <stdio.h>
#include <stdlib.h>

int num;
FILE *fptr;

int main (  void )  {
    if ((fptr = fopen("C:\\program.txt","r")) == NULL){
       printf("Error! opening file");
       exit(1);
   }

   for(n = 1; n < 5; ++n)
   {
      fread(&num, sizeof(struct threeNum), 1, fptr); 
      printf("n1: %d\tn2: %d\tn3: %d", num.n1, num.n2, num.n3);
   }
   fclose(fptr); 
  
   return 0;
}