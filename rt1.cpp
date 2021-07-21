# include <iostream>
# include <vector>

using namespace std;

class shape {
  public:
      int width, height, radius;
      long int get_area( void ) {
          return ( width*height*radius);
      }
};


int main ( void )  {
  //Some Suite
  shape rect;
  rect.width = 12;
  rect.height = 14;
  rect.radius = 10;
  cout << rect.get_area() << endl;
  return(0);
}
