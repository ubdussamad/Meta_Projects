#include <iostream>
#include <vector>



typedef struct return_node_t return_node_t;

struct return_node_t {
  int num;
  int denum;
};

using namespace std;

int find_common ( int x ,  int y);
return_node_t discreet_non_common_terms ( int x , int y );

int main( void ) {
  // Suite
  double num_product = 1;
  double denum_product = 1;
  
  for (int i=10;i<99;i++) {
    for (int j=10;j<99;j++) {
      //cout << "i and j are:" << i << "," << j << endl;
            // Suite for Processing
      if ( (find_common(i,j)!=-1) and (find_common(i,j) != 0 )){
	//cout <<"A" << endl;
	//So there is a common term
	if ( i<j ) {
	  //So the fraction is less than 1
	  return_node_t buffer = discreet_non_common_terms( i , j );
	  //cout << "B" <<  endl;
	  //cout << " num: " << buffer.num << " denum: " << buffer.denum << endl;
	  if (buffer.num == 0 or buffer.denum == 0) {
	    cout << "Rejecting" << endl;
	    continue;
	  }
     if ( (buffer.num != buffer.denum) and i/j == buffer.num/buffer.denum) {
            //cout <<"C" << endl;
	    if (  (i%j)%(buffer.num%buffer.denum) == 0) {
	    	      //Success
	      //cout <<  "\t\tMade it to the finals!"<<i<< "," << j << endl;
	      cout <<  num_product << "," << denum_product << endl;
	      num_product *= i;
	      denum_product *= j;
	    }
	  }
	}
	
      }
      else {
	continue;
      }
      //cout << endl;
    }
  }
  std::cout << num_product << "," << denum_product << std::endl;
  return(0);
}

// Subroutine for testing if they have a common term
int find_common (  int x , int y ) {
  // Find discreet terms for x
  int x_discreet[2] = {x/10 , x%10};
  int y_discreet[2] = {y/10 , y%10};
  if ( x_discreet[0] == y_discreet[0] or x_discreet[0] == y_discreet[1] ){
    return(x_discreet[0]);
  }
  else if (x_discreet[1] == y_discreet[0] or x_discreet[1] == y_discreet[1]){
    return(x_discreet[1]);
  }
  else {
    return(-1); //If there is not common term
  }
}

 return_node_t discreet_non_common_terms ( int x , int y ) {
   //Finds the ratio of non common
   //cout << "Finding non C @ " << x << "," << y << endl;
   int common_term = find_common(x,y);
   int x_discreet[2] = {x/10 , x%10};
   int y_discreet[2] = {y/10 , y%10};
   return_node_t buffer;
   buffer.num = (x_discreet[0] == common_term) ? x_discreet[1] : x_discreet[0];
   buffer.denum = (y_discreet[0]) == common_term ? y_discreet[1] : y_discreet[0];
   return( buffer ) ;
 } 
