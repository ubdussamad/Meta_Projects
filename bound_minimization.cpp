# include <iostream>
# include <vector>
# include <cmath>

//Using the main namespae (This is sometimes discouraged)
using namespace std;

// Declaring Prototype for g(x)
double g ( double x );

int main (  void ) {
  // Some suite for main processing
  double lower_bound = 1.5; // It comes negative 
  double upper_bound = 2.5; // It comes positive
  
  int count= 15;

  while ( count )  {
    count--;  // Decrement count everytime so as to make this loop terminating

    float mean = ( lower_bound +  upper_bound ) / 2.0; // We calculate the mean

    if ( g(mean) > 0.0000 ) { // It's positive in some weird sense but it is.
      lower_bound = mean;
    }
    else {
      upper_bound = mean;
    }
  }
  
  cout << "The UB: " << upper_bound << " and the LB: " << lower_bound << endl;
  cout << "The mean of the two bounds is: " << (upper_bound+lower_bound)/2.0 << endl;
  
  return(0);
}

double g (  double  x ) {
  // We're supposed to return: 1.2000 - x * log(x) double log (double x);
  return ( 1.2000 - ( x * log10(x) ) );
}
