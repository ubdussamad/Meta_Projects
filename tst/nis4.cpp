#include <iostream>
#include "matrix_.h"

#define LOG std::cout <<
#define X << std::endl

template <typename T>
T det ( short dim , matrix_<T> arr);

int main (  void )  {
  matrix_<int> x(4,4);

  x[0][0] = -3;
  x[0][1] = 9;
  x[0][2] = 7;
  x[0][3] = 9;

  x[1][0] = 3;
  x[1][1] = 9;
  x[1][2] = 7;
  x[1][3] = -6;

  x[2][0] = 40;
  x[2][1] = 8;
  x[2][2] = -1;
  x[2][3] = 5;

  x[3][0] = 3;
  x[3][1] = 6;
  x[3][2] = 3;
  x[3][3] = 7;
  

  x.printStirng();

  std::cout << "Det is: " << det(4,x) << std::endl;

  
  return (0);
}

template <typename T>
T det ( short dim , matrix_<T> arr) {
  T ret_val[dim];
  short dim_ctr = 0;

  if (dim==2) { // 2x2 Case
    return ((arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]));
  }
  else {
    for (short i=0; i < dim; i++) {
      T pilot = arr[0][i];
      T cf;
      short x = dim-1;
      matrix_<T> tmp_arr(x,x);
      for ( short j = 0; j < (dim-1) ; j++ ) {
	      for ( short k = 0; k < (dim-1) ; k++ ) {
	         tmp_arr[j][k] = arr[j+1][k<i ? k : k+1];
        }
      }
      cf = det( (dim-1) , tmp_arr );
      ret_val[dim_ctr++] =  cf * pilot;
    }
  }
  T ans = 0;
  bool flg(1);
  for (short i = 0; i < (dim_ctr) ; i++ ) {
    if (flg) {
      ans += ret_val[i];
      flg=0;
    }
    else {
      ans -= ret_val[i];
      flg = 1;
    }
  }
  return(ans);
}
    
      
      
  
